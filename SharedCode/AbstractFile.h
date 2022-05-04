#pragma once
/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* AbstractFile.h
* Contains the declarations for the AbstractFile class which provides methods for the different types of files
* It also contains the enumerations for our program
*/
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
	//adding clone function
	virtual AbstractFile* clone(std::string name) = 0;
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
	commandDidntWork = 12,
	commandWorked = 0, //command was successful
	invalidFileAddition = 13, //addition of a new file failed
	invalidTag = 14, //user entered an invalid input for indicating they want to create an encrypted file
	invalidCatCommand = 15,
	catCommandSuccess = 0,
	displayError = 17,
	displaySuccess = 0,
	copyCommandError = 18,
	copyCommandSuccess = 0,
	errorMacroCommand = 19,
	catSaveandQuit = 20,
	catQuit = 21


};
//enums for constants 
enum {
	start = 0,
	first = 1,
	validCompare = 1,
	evenDivisor = 2,
	length = 5,
	maxInput = 20
};

