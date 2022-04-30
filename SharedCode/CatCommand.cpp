/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* CatCommand.h
* Contains the declarations for the CatCommand class which inherits publicly from AbstractCommand
*/
#pragma once
#include "AbstractFile.h"
#include "AbstractFileFactory.h"
#include "LSCommand.h"
#include "BasicDisplayVisitor.h"
#include "CatCommand.h"
#include <sstream>
using namespace std;
//constructor initializes our file system variable
CatCommand::CatCommand(AbstractFileSystem* afs) : fileSystem(afs) {}
void CatCommand::displayInfo() {
	cout << "Append file with 'cat' then the file name then '-a' or write the file with 'cat' then the file name" << endl;
}
int CatCommand::execute(string userInput) {
	//if the user input is empty, we want to let the user know and then display information
	if (userInput.empty()) {
		cout << "Empty cat parameters" << endl;
		this->displayInfo();
		return invalidCatCommand;
	}
	istringstream iss(userInput);
	string name;
	string totalInput;
	string tag;
	iss >> name;
	iss >> tag;
	
	AbstractFile* file = fileSystem->openFile(name);
	if (file == nullptr) {
		cout << "Error in retrieving file" << endl;
		fileSystem->closeFile(file);
		return invalidCatCommand;
	}
	else if (!name.empty() && tag =="-a") {
		AbstractFileVisitor* vis = new BasicDisplayVisitor();
		file->accept(vis);
		cout << "Input something to add to file, wq to save and quit, or q to quit" << endl;
		bool isSaved = false;
		bool userDidntQuit = true;
		string inputString;
		while (userDidntQuit) {
			getline(cin, inputString);
			//if the user wants to quit
			if (inputString == ":q") {
				userDidntQuit = false;
			}
			//if the user wants to save and quit
			else if (inputString == ":wq") {
				userDidntQuit = false;
				isSaved = true;
			}
			//if the user hasn't quit yet then we want to appedn their input to the total 
			else {
				totalInput += inputString;
				//resetting our input string 
				inputString = "";
			}
		}
		//if the user didn't save and quit
		if (userDidntQuit == false && isSaved==false) {
			cout << "Quit without saving" << endl;
			fileSystem->closeFile(file);
			return catCommandSuccess;
		}
		//if the user saved and quit
		else {
			vector<char> hold(totalInput.begin(), totalInput.end());
			int appendResult = file->append(hold);
			if (appendResult != successful) {
				cout << "could not append to the file" << endl;
				return invalidCatCommand;
			}
			else {
				cout << "Successfully appended input to file" << endl;
				return catCommandSuccess;
			}
		}

	}
	//if the name and tag are both empty - write file
	else if(name=="" && tag =="") {
		cout << "Writing: " << file->getName() << ". Please enter :wq to save and quit or just :q to quit without saving" << endl;
		string userInput;
		
		bool userQuit = false;
		bool userSaved = false;
		string totalInput;
		while (!userQuit) {
			getline(cin, userInput);
			totalInput += userInput;
			if (userInput == ":q") {
				userSaved = false;
				userQuit = true;
			}
			else if (userInput == ":wq") {
				userSaved = true;
				userQuit = true;
			}
			else {
				//not super sure what to put here
				totalInput += "\n";
			}

		}
		if (userQuit && userSaved) {
			vector<char> hold(totalInput.begin(), totalInput.end());
			if (file->write(hold) == successful) {
				cout << "Successfully wrote to file" << endl;
				return catCommandSuccess;
			}
			else {
				cout << "Could not write to file" << endl;
				return invalidCatCommand;
			}
		}
		else if (userQuit && !userSaved) {
			cout << "Exited without saving" << endl;
			return catCommandSuccess;
		}

	}
	else {
		cout << "Invalid cat command" << endl;
		fileSystem->closeFile(file);
		return invalidCatCommand;
	}
	

}