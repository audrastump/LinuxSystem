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
int RemoveCommand::execute(std::string name) {
	
	if (this->fileSys->deleteFile(name) == successful) {
		cout << "File was deleted successfully" << endl;
		return successful;
	}
	else if(name.empty()) {
		cout << "No file entered to delete" << endl;
		return invalidFile;
	}
	else {
		cout << "File not found" << endl;
		return invalidFile;
	}
}
void RemoveCommand::displayInfo() {
	cout << "Enter the file name to delete it form your system" << endl;
}