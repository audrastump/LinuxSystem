// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"
#include <string>

using namespace std;

int SimpleFileSystem::addFile(string name, AbstractFile* filePointer) {
    if (fileMap.find(name) != fileMap.end()) { 
        return fileAlreadyExists;
    }
    else {
        if (filePointer != nullptr) {
            fileMap.insert({ name,filePointer });
            return successful;
        }
        return invalidFile;
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
    if(extension.compare("img") != validCompare){
        AbstractFile* i = new ImageFile(name);
        pair<string, AbstractFile*> file (name, i);
        this->fileMap.insert(file);
        return successful;
    }
    else if(extension.compare("txt") != validCompare){
        AbstractFile* t = new TextFile(name);
        pair<string, AbstractFile*> file (name, t);
        this->fileMap.insert(file);
        return successful;
    }
    return invalidFile;
}


AbstractFile* SimpleFileSystem::openFile(string name){
    if(this->fileMap.count(name) >=validCompare){
        if(this->openFiles.count(fileMap.at(name)) == start){
            this->openFiles.insert(fileMap.at(name));
            return fileMap.at(name);
        }
        return nullptr;
    }
    return nullptr;
}
int SimpleFileSystem::closeFile(AbstractFile* f){
    if (openFiles.count(f) >= validCompare) {
        auto it = openFiles.find(f);
        openFiles.erase(it);
        return successful;
    }
    else {
        return invalidFile;
    }
}
int SimpleFileSystem::deleteFile(std::string name) {
    if (fileMap.count(name)>=1){
        if (openFiles.count(fileMap.at(name))>=1) {
            return fileNotClosed;
        }
        else {
            delete fileMap.at(name);
            fileMap.erase(name);
            return successful;
        }
       
    }
    else {
        return invalidFile;
    }
}
