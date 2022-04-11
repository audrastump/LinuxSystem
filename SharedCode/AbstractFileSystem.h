#pragma once
// declaration of the interface all file systems provide goes here
#include "AbstractFile.h"
class AbstractFileSystem {
public:
	virtual int addFile(std::string name, AbstractFile* a) = 0;
	virtual int createFile(std::string name) = 0;
	virtual int deleteFile(std::string name) = 0;
	virtual AbstractFile* openFile(std::string name) = 0;
	virtual int closeFile(AbstractFile *a) = 0;

};