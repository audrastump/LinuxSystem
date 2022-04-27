#pragma once
// declaration of SimpleFileSystem class goes here
#include <map>

#include <set>

#include "AbstractFileSystem.h"
#include <string>

class SimpleFileSystem : public AbstractFileSystem {
	std::map<std::string, AbstractFile*> fileMap;
	std::set<AbstractFile*> openFiles;

public:
	virtual int addFile(std::string nameOfFile, AbstractFile* file) override;
	virtual int deleteFile(std::string nameOfFile) override;
	virtual AbstractFile* openFile(std::string nameOfFile) override;
	virtual int closeFile(AbstractFile* nameOfFile) override;
	virtual set<string> getFileNames() override;
};