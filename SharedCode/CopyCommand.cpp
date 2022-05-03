#include"CopyCommand.h"
#include <sstream>
using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* files) : fileSys(files) {}

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
		auto newFileName = copiedFile->getName();
		auto ret = fileSys->addFile(newFileName, copiedFile);
		fileSys->closeFile(file);
		return ret;
	}
	else {
		return copyCommandError;
	}
}



void CopyCommand::displayInfo() {
	cout << "To copy files, can be invoked with the command: cp <file_to_copy> <new_name_with_no_extension>" << endl;
}