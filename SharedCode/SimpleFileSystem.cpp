/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* SimpleFileSystem.cpp
* Contains the definitions for the SimpleFileSYstem class which provides methods for the different types of files
* such as adding, opening, closing, and deleting files, as well as listing the file names as a set that are currently in the system
*/
#pragma once
#include "SimpleFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"
#include <string>

using namespace std;
//this adds a file to our simple file system
int SimpleFileSystem::addFile(std::string name, AbstractFile* filePointer) {
    //using the find method to search through our file map
    if (fileMap.find(name) != fileMap.end()) { 
        //if it gets stuck that means that the file already exists in our map
        return fileAlreadyExists;
    }
    else {
        //if the filepointer is null, that means we can insert it
        if (filePointer != nullptr) {
            //popping it into the fileMap
            fileMap.insert({ name,filePointer });
            return successful;
        }
        return invalidFile;
    }
}




AbstractFile* SimpleFileSystem::openFile(std::string name){
    //if there is at least on instance of this in the file Map
    if(this->fileMap.count(name) >=validCompare){
  
        if(this->openFiles.count(fileMap.at(name)) == start){
            //opening the fiile
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
    //if there is at least one instance of the name
    if (fileMap.count(name)>=validCompare){
        //if we can't open it
        if (openFiles.count(fileMap.at(name))>=validCompare) {
            return fileNotClosed;
        }
        //otherwise we want to delete it
        else {
            delete fileMap.at(name);
            //getting it out of the map
            fileMap.erase(name);
            return successful;
        }
       
    }
    else {
        return invalidFile;
    }
}
//implementation of the getFileNames (lab 5 part 1), which returns a set of all the names in our fileMap
set<string> SimpleFileSystem::getFileNames() {
    //declaring our set of fileNames, names
    set<string> names;
    //iterating through all the values in our file map
    for (auto it = fileMap.begin(); it != fileMap.end(); ++it) {
        //inserting each first value (the name) into our names set
        names.insert(it->first);
    }
    return names;
}