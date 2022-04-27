#pragma once
// declaration of the interface all file systems provide goes here
#pragma once
#include <string>
#include <vector>
#include <set>
#include "AbstractFile.h"
using namespace std;
class AbstractFileSystem {
public:
	virtual int addFile(std::string name, AbstractFile* abFile) = 0;
	
	virtual int deleteFile(std::string nameOfFile) = 0;
	virtual AbstractFile* openFile(std::string nameOfFile) = 0;
	virtual int closeFile(AbstractFile *abFile) = 0;
	//added pure virtual function to the AFS that returns set with all the names of the file system
	//this will be implemented in SimpleFIleSystem
	virtual set<string> getFileNames() = 0;
};