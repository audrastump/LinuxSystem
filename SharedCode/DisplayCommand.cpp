#pragma once
/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* DisplayCommand.h
* Contains the definitions for the DisplayCommand class which inherits publicly from AbstractCommand and has a constructor,
* execute, and displayInfo method 
*/
#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
using namespace std;
#include <string>
#include <sstream>
DisplayCommand::DisplayCommand(AbstractFileSystem* afs) : fileSys(afs) {}


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
		for (char c : fileContents) {
			cout << c;
		}
		cout <<""<< endl;
		fileSys->closeFile(curFile);
		return displaySuccess;
	}
	else {

		AbstractFileVisitor* vis = new BasicDisplayVisitor();
		curFile->accept(vis);
		cout << endl;
		fileSys->closeFile(curFile);
		return displaySuccess;
	}


}
//int DisplayCommand::execute(string userInput) {
//
//	string name;
//	string tag;
//	istringstream iss(userInput);
//	//extracting the name and tag 
//	iss >> name;
//	iss >> tag;
//
//	//ensuring it is actually in the file system
//	set<string> namesOfFiles = fileSys->getFileNames();
//	set<string>::iterator it = namesOfFiles.find(name);
//	if (it == namesOfFiles.end()) {
//		return displayError;
//	}
//	//if there is an invalid file we need to do something
//	AbstractFile* curFile = fileSys->openFile(name);
//	if (curFile == nullptr) {
//		return displayError;
//	}
//
//	//check if -d is present
//	if (tag == "-d") {
//		//putting curFile into a character vector
//		vector<char> fileContents = curFile->read();
//		for (char c : fileContents) {
//			cout << c;
//		}
//		cout << "" << endl;
//		fileSys->closeFile(curFile);
//		return displaySuccess;
//	}
//	else {
//
//		AbstractFileVisitor* vis = new BasicDisplayVisitor();
//		curFile->accept(vis);
//		fileSys->closeFile(curFile);
//		return displaySuccess;
//	}
//
//
//}

void DisplayCommand::displayInfo() {
	cout << "Displays files, enter command: ds 'filename' [-d]" << endl;
}

