#include"CopyCommand.h"
#include <sstream>
using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* files) : fileSys(files) {}

//use prototype pattern because objects should be in charge of creating their own copies (especially if I
// can't get private member variables)
int CopyCommand::execute(std::string commandName) {

	string name;
	string tag;
	istringstream iss(commandName);
	//extracting the name and tag 
	iss >> name;
	iss >> tag;
	set<string> fileNames = fileSys->getFileNames();
	set<string>::iterator it = fileNames.find(name);
	//if the command name cannot be found in the file system we will return an invalid file
	if (it == fileNames.end()) {
		cout << "Could not find command name" << endl;
		return invalidFile;
	}
	
	AbstractFile* curFile = fileSys->openFile(name);
	fileSys->closeFile(curFile);

	AbstractFile* newFile = curFile->clone(tag);
	if (fileSys->addFile(newFile->getName(), newFile) == successful) {
		return copyCommandSuccess;
	}
	delete newFile;
	return copyCommandError;
}

void CopyCommand::displayInfo() {
	cout << "To copy files, can be invoked with the command: cp <file_to_copy> <new_name_with_no_extension>" << endl;
}