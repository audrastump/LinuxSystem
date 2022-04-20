#pragma once
// studio 18 - file factory interface declared here
#include "AbstractFile.h"
#include <string>
//interface for AbstractFileFactory
class AbstractFileFactory {

public:
	//createFile takes in a std string and returns pointer to abstractFile
	virtual AbstractFile* createFile(std::string argument) = 0;
};
