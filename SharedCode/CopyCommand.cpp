/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* CopyCommand.cpp
* Contains the declarations for the CopyCommand class which 
*/
#include"CopyCommand.h"
#include <sstream>
using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* files) : fileSys(files) {}
//execute method copies the command
int CopyCommand::execute(std::string command) {

	//extracting the file name and the new name
	string firstName;
	string newName;

	istringstream iss(command);
	iss >> firstName;
	iss >> newName;
	set<string> fileSet;
	fileSet = fileSys->getFileNames();

	//if the original name doesn't already exist in the file set
	if (fileSet.find(firstName) == fileSet.end()) {
		return copyCommandError;
	}
	//trying to find if there is another file of that new name
	string fullname = newName + firstName.substr(firstName.find('.'));
	if (fileSet.find(fullname) == fileSet.end()) {
		//copy the files
		AbstractFile* file = fileSys->openFile(firstName);
		AbstractFile* copiedFile = file->clone(fullname);
		//getting our new file name, then adding the newfile name to the file system
		auto newFileName = copiedFile->getName();

		auto ret = fileSys->addFile(newFileName, copiedFile);
		fileSys->closeFile(file);
		return ret;
	}

	else {
		return copyCommandError;
	}
}


//usage function
void CopyCommand::displayInfo() {
	cout << "To copy files, please enter cp 'file' 'new name' " << endl;
}