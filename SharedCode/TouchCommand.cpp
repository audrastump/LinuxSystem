#include "TouchCommand.h"
#include <iostream>
#include "../SharedCode/PasswordProxy.h"
#include <sstream>
using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem*newAFS, AbstractFileFactory*newAFF): afs(newAFS), aff(newAFF) {

}
void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command touch <filename>" << endl;
}
int TouchCommand::execute(std::string s) {

	string name;
	if (s.find_last_of('/') != string::npos) {
		//Using the file name to create a new file
		name = s.substr(s.find_last_of('/') + 1, string::npos);
	}
	else {
		name = s;
	}
	AbstractFile* abFile = aff->createFile(name);
	if (abFile == nullptr) { // file creation failed
		cout << "Error creating the file" << endl;
		return 2;
	}
	int result = afs->addFile(name,abFile);
	if (result != 0) {
		cout << "Error adding to file system" << endl;
		delete abFile;
		return 1;
	}
	return result;
}