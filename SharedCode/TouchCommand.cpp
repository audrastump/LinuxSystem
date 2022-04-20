#include "TouchCommand.h"
#include <iostream>

TouchCommand::TouchCommand(AbstractFileSystem*newAFS, AbstractFileFactory*newAFF): afs(newAFS), aff(newAFF) {

}
void TouchCommand::displayInfo() {
	std::cout << "touch creates a file, touch can be invoked with the command touch <filename>" << std::endl;
}
int TouchCommand::execute(std::string s) {
	//AbstractFile* createFile(std::string argument) = 0;
	AbstractFile* a = aff->createFile(s);
	if (a == nullptr) {
		return 8;
	}
	int check = afs->addFile(s, a);
	if (check != 0) {
		delete a;
		return check;
	}
	
}