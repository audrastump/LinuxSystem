#include "TouchCommand.h"
#include <iostream>
#include "../SharedCode/PasswordProxy.h"
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
		if (tag == "-p") {
			cout << "Please enter password" << endl;
			cin >> key;
			//creating new file and passwordProxy
			AbstractFile* file = aff->createFile(fileName);
			PasswordProxy* pass = new PasswordProxy(file, key);
			//if they entered a null file pointer return an error
			if (file == nullptr) {
				return invalidFileAddition;
			}
			else {
				//try to add file to the file system 
				if (afs->addFile(fileName, pass) == successful) {
					return commandWorked;
				}
				else {
					return invalidFileAddition;
				}
			}
			return invalidFileAddition;	
		}
		//they entered something invalid as their second input
		else {
			return invalidTag;
		}
		
	}
	return invalidFileAddition;
}