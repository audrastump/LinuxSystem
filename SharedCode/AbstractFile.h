#pragma once
enum {
	successful = 0,
	invalidImage = 1,
	validCompare = 1,
	sizeDoesntMatch = 2,
	errorAppending = 3, 
	fileAlreadyExists = 4,
	invalidFile = 5,
	fileNotClosed = 6,
	passwordMismatch =7,
	userQuit = 8,
	userHelp = 9,
	executed = 10,
	cantFindCommand = 11,
	commandWorked = 12,
	invalidFileAddition = 13,
	invalidTag = 14


};
enum {
	start = 0,
	first = 1,
	evenDivisor = 2,
	maxInput = 20
};
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



