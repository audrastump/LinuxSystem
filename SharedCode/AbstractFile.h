#pragma once
/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* AbstractFile.h
* Contains the declarations for the AbstractFile class which provides methods for the different types of files
* It also contains the enumerations for our program
*/
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include "AbstractFileVisitor.h"
#include <string>
#include <iostream>
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
//enums for the return values/errors
enum {
	successful = 0, //everything worked!! yay!!
	invalidImage = 1,
	sizeDoesntMatch = 2,
	errorAppending = 3,
	fileAlreadyExists = 4, //user tried to enter a file that already existed in the fileSystem
	invalidFile = 5, 
	fileNotClosed = 6,
	passwordMismatch = 7, //user entered the wrong password
	userQuit = 8, //user quit the program
	userHelp = 9, //user entered the help command
	executed = 10,
	cantFindCommand = 11,
	commandWorked = 12, //command was successful
	invalidFileAddition = 13, //addition of a new file failed
	invalidTag = 14, //user entered an invalid input for indicating they want to create an encrypted file
	invalidCatCommand = 15,
	catCommandSuccess = 16,
	displayError = 17,
	displaySuccess = 0


};
//enums for constants 
enum {
	start = 0,
	first = 1,
	validCompare = 1,
	evenDivisor = 2,
	maxInput = 20
};

