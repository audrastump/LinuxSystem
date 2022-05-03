#pragma once
/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* TouchCommand.cpp
* Contains the definitions for the TouchCommand class which provides methods for displaying the information on how to create a file,
* executing the command asked from the user, and determining if the user wants to encrypt the file with a password
*/
#include "TouchCommand.h"
#include <iostream>
#include "PasswordProxy.h"
#include <sstream>
using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem*newAFS, AbstractFileFactory*newAFF): afs(newAFS), aff(newAFF) {

}
//usage function for displaying how to use the touch command method
void TouchCommand::displayInfo() {
	cout << "Please enter either touch <filename> to create a file or touch <filename> -p to create a password protected file" << endl;
}
int TouchCommand::execute(std::string inputString) {
	//creating a input string stream to parse potential additional word
	istringstream iss(inputString);

	//checking to see if there are one or two words
	bool isSingularWord = true;
	for (int i = start; i < inputString.size(); ++i) {
		if (inputString[i] == ' ') {
			isSingularWord = false;
		}
	}
	//isn't using a password
	if (isSingularWord) {
		//creating a new file under the name given by the input string
		AbstractFile* f = aff->createFile(inputString);
		if (f == nullptr) {
			return invalidFileAddition;
		}
		else {
			if (afs->addFile(inputString, f) == successful) {
				return commandWorked;
			}
			else {
				return invalidFileAddition;
			}
		}
		return invalidFileAddition;
	}
	string fileName;
	string tag;
	string key;
	//reading in our file name and password
	if (iss >> fileName && iss >> tag) {
		//making sure they entered -p
		if (tag.compare("-p") == 0) {

		
			string newKeyword;
			cout << "Please enter the password" << endl;
			getline(cin, newKeyword);
			AbstractFile* af = this->aff->createFile(fileName);
			PasswordProxy* pp = new PasswordProxy(af, newKeyword);
		
			if (af == nullptr) {
				delete af;
				return cantFindCommand;
			}
			else {
				if (this->afs->addFile(fileName, pp) == 0) {
					return successful;
				}
				else {
					return cantFindCommand;
				}
			}
		}
		//they entered something invalid as their second input
		else {
			return invalidTag;
		}
		
	}
	return invalidFileAddition;
}