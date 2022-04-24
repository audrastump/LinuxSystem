// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"
#include <string>

using namespace std;

int SimpleFileSystem::addFile(string name, AbstractFile* filePointer) {
    if (fileMap.find(name) != fileMap.end()) { // file exists already
        return 1;
    }
    else {
        if (filePointer != nullptr) {
            fileMap.insert({ name,filePointer });
            return 0;
        }
        return 1;
    }
}

int SimpleFileSystem::createFile(std::string name){
    bool pReached = false;
    std::string extension = "";
    for(auto it = name.begin(); it != name.end(); it++){
        if(pReached){
            extension += *it;
        }
        if(*it == '.') {
            pReached = true;
        }
    }
    if(extension.compare("img") != 1){
        AbstractFile* i = new ImageFile(name);
        pair<string, AbstractFile*> file (name, i);
        this->fileMap.insert(file);
        return 0;
    }
    else if(extension.compare("txt") != 1){
        AbstractFile* t = new TextFile(name);
        pair<string, AbstractFile*> file (name, t);
        this->fileMap.insert(file);
        return 0;
    }
    return 1;
}


AbstractFile* SimpleFileSystem::openFile(string name){
    if(this->fileMap.count(name) >=1){
        if(this->openFiles.count(fileMap.at(name)) == 0){
            this->openFiles.insert(fileMap.at(name));
            return fileMap.at(name);
        }
        return nullptr;
    }
    return nullptr;
}
int SimpleFileSystem::closeFile(AbstractFile* f){
    if (openFiles.count(f) >= 1) {
        auto it = openFiles.find(f);
        openFiles.erase(it);
        return 0;
    }
    else {
        return 1;
    }
}
int SimpleFileSystem::deleteFile(std::string name) {
    if (fileMap.count(name)>=1){
        if (openFiles.count(fileMap.at(name))>=1) {
            return 1;
        }
        else {
            delete fileMap.at(name);
            fileMap.erase(name);
            return 0;
        }
       
    }
    else {
        return 1;
    }
}
