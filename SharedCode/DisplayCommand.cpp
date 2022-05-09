#pragma once
/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* DisplayCommand.h
* Contains the definitions for the DisplayCommand class which has a constructor,
* execute, and displayInfo method 
*/

#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
using namespace std;
#include <string>
#include <sstream>

DisplayCommand::DisplayCommand(AbstractFileSystem* afs) : fileSys(afs) {}

//executes our display command 
int DisplayCommand::execute(string userInput) {

	string name;
	string tag;
	istringstream iss(userInput);
	//extracting the name and tag 
	iss >> name;
	iss >> tag;

	//ensuring it is actually in the file system
	set<string> namesOfFiles = fileSys->getFileNames();
	set<string>::iterator it = namesOfFiles.find(name);
	if (it == namesOfFiles.end()) {
		return displayError;
	}
	//if there is an invalid file we need to do something
	AbstractFile* curFile = fileSys->openFile(name);
	if (curFile == nullptr) {
		return displayError;
	}

	//check if -d is present
	if (tag=="-d") {
		//putting curFile into a character vector
		vector<char> fileContents = curFile->read();
		//iterating through and printing all the file contents
		for (char c : fileContents) {
			cout << c;
		}
		cout <<""<< endl;
		//returning successful and closing the file 
		fileSys->closeFile(curFile);
		return displaySuccess;
	}
	else {
		//if d is not present, we will create a new BDV, accept the visitor, then close the file 
		AbstractFileVisitor* vis = new BasicDisplayVisitor();
		curFile->accept(vis);
		cout << endl;
		fileSys->closeFile(curFile);
		return displaySuccess;
	}


}


void DisplayCommand::displayInfo() {
	cout << "To display files, please enter command: ds 'file name' (-d)" << endl;
}

