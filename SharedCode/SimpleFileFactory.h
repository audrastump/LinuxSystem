#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#pragma once
#include "AbstractFileFactory.h"
//file factory that inherits from AbstractFileFactory interface
class SimpleFileFactory : public AbstractFileFactory {
public:
	//redefines implementation of createFile method of SimpleFileSystem
	virtual AbstractFile* createFile(std::string path) override;
};