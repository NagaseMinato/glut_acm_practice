#! /usr/bin/python

import json
import os


def fileChecking(fmap):
    for _root, _dirs, fileList in os.walk('src'):
        pass

    diffList = list(set(fmap.values()).difference(set(fileList)))
    if len(diffList)!=0:
        raise Exception("unmapped file existing")

def genMakeFile(fmap):
    makefile = open("Makefile","w")
    content =\
        "GCC_FLAG = -std=c++11 -O3  -Wall -pedantic\nALL_PROGRAMS = "
    for eachFileName in fmap.keys():
        content += eachFileName
        content += " "
    content += "\n\n"
    content += "all: $(ALL_PROGRAMS)\n\n"

    for [k,v] in fmap.items():
        content += k
        content += ":\n\t"
        content += "g++ $(GCC_FLAG) src/"
        content += v
        content += " -o bin/$@\n"

    content += "clean:\n\tcd bin;rm $(ALL_PROGRAMS);\n"
    makefile.write(content)

def getFileMapping():
    fd = open("fmap.json")
    res = json.load(fd)
    return res




def main():
    fmap = getFileMapping()
    fileChecking(fmap)
    genMakeFile(fmap)


main()
