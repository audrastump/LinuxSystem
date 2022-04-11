#pragma once
// declaration of SimpleFileSystem class goes here
#include <map>
#include <set>
#include "AbstractFileSystem.h"
class SimpleFileSystem : public AbstractFileSystem {
	std::map<std::string, AbstractFile*> fileMap;
	std::set<AbstractFile*> openFiles;
public:
	int addFile(std::string name, AbstractFile* a);
	int createFile(std::string name);
	int deleteFile(std::string name);
	AbstractFile* openFile(std::string name);
	int closeFile(AbstractFile* a);

};