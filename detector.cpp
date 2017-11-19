#include <cstdio>
#include <cstdlib>
#include <dirent.h>
#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <map>
#include <sys/wait.h>

class FileReader{
public:
    explicit FileReader(const char * path):path(path){};
    FileReader(const FileReader &) = delete;
    FileReader & operator=(const FileReader &) = delete;

    std::vector<std::string> & getFiles(){
        if(files.empty())
            readBinaryFiles();
        return files;
    }

    const std::string & getParentDir() const{
        return path;
    }

private:
    void readBinaryFiles();

private:
    std::vector<std::string> files;
    std::string path;
};

class Detector{
public:
    explicit Detector(const char * path):reader(path){}

    void work();

    void createSubprocess(const std::string args);

private:
    FileReader reader;
    std::map<pid_t,bool> executed;
};

void Detector::createSubprocess(const std::string args){
    pid_t pid;
    pid = fork();
    if(pid==0){
        int res;
        res = execl("/bin/bash","sh","-c",args.c_str(),nullptr);
        if(res == -1){
            perror("execl");
        }
        exit(-1);
    }
    int status;
    if(waitpid(pid,&status,0)==-1){
        perror("waitpid");
        return;
    }
}

void Detector::work() {
    for(const auto &file : reader.getFiles()){
        std::string prog(reader.getParentDir());
        prog +="/";
        prog += file;
        std::string data(reader.getParentDir());
        data +="/../test/";
        data += file;
        data += ".data";
        std::string res(prog);
        res +=" < ";
        res += data;
        std::cout<<res<<"\n";
        createSubprocess(res);
    }
}

void FileReader::readBinaryFiles() {
    DIR *dir;
    struct dirent *ptr;

    if ((dir=opendir(path.c_str())) == nullptr) {
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr=readdir(dir)) != nullptr) {
        if(ptr->d_type == DT_REG)       //file
            files.emplace_back(ptr->d_name);
        else
            continue;
    }
    closedir(dir);
}



int main(int argc, char *argv[]) {
    Detector detector(argv[1]);
    detector.work();
    return 0;
}
