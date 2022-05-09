/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* RemoveCommand.h
* Contains the definitons for the RemoveCommand class which inherits from the AbstractCommand class and removes a file 
* from the list of files
*/
#pragma once
#include <iostream>
#include "RemoveCommand.h"
using namespace std;
//constructor initializes the abstract file system pointer
RemoveCommand::RemoveCommand(AbstractFileSystem* abFileSys) : fileSys(abFileSys) {

}
//takes the name entered and removes the corresponding command
int RemoveCommand::execute(std::string name) {
	//if it successfully deletes the file (returns zero), then we return zero
	if (this->fileSys->deleteFile(name) == successful) {
		cout << "File was deleted successfully" << endl;
		return successful;
	}
	//if the name is empty, we want to return invalid file
	else if(name.empty()) {
		cout << "No file entered to delete" << endl;
		return invalidFile;
	}
	//if we cant find the file, we will return invalid file
	else {
		cout << "File not found" << endl;
		return invalidFile;
	}
}
//gives a usage message about displaying the information
void RemoveCommand::displayInfo() {
	cout << "Enter the file name to delete it form your system" << endl;
}