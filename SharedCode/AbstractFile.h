#pragma once

// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include "AbstractFileVisitor.h"

#include <string>
class AbstractFile {
public:
	virtual ~AbstractFile() = default;
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char>) = 0;
	virtual int append(std::vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	//added pure virtual abstract file visitor function
	virtual void accept(AbstractFileVisitor* a) = 0;
};



