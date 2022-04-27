#pragma once
#include <string>
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
class AbstractCommand {
public: 
	virtual ~AbstractCommand()=default;
	virtual int execute(std::string s) = 0;
	virtual void displayInfo() = 0;
};
