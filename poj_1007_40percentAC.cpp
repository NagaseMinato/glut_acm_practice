
#include <iostream>
#include <map>

int inversionNumber(const std::string & str) {
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        for (int k = i + 1; k < str.size(); k++) {
            if (str[i] > str[k]) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    std::multimap<int, char *> m;

    int strLen;
    int strCount;
    std::cin >> strLen >> strCount;
    for (int i = 0; i<strCount; i++) {
        char * DNAStr = new char[strLen + 1];
        std::cin >> DNAStr;
        int n = inversionNumber(std::string(DNAStr));
        m.insert(std::make_pair(n, DNAStr));
    }
    for (std::multimap<int, char*>::iterator iter = m.begin(); iter != m.end(); iter++) {
        std::cout << iter->second << "\n";
    }
    return 0;
}


