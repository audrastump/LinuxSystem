/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* CatCommand.cpp
* Contains the declarations for the CatCommand class which inherits publicly from AbstractCommand and prompts the user to write to the file or append to a file
*/
#pragma once
#include "AbstractFile.h"
#include "AbstractFileFactory.h"
#include "LSCommand.h"
#include "BasicDisplayVisitor.h"
#include "CatCommand.h"
#include <sstream>
using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs) : fileSystem(afs) {}
//display info gives our usage message for the function
void CatCommand::displayInfo() {
	cout << "Please enter 'cat' to add data to a file then the file name then '-a' or write the file with 'cat' then the file name" << endl;
}
int CatCommand::execute(std::string s) {
	//finding the first and last string 
	istringstream iss(s);
	string fileName; string tag;
	iss >> fileName;
	iss >> tag;
	//creating constnats for save and save quit
	string quit = ":q";
	string saveQuit = ":wq";

	AbstractFile* file = fileSystem->openFile(fileName);
	//check to see if the file is null, which means there was an error appending
	if (file == nullptr) {
		fileSystem->closeFile(file);
		//returning an error message
		return invalidCatCommand;
	}

	//if there is an "a " tag then we want to append
	if (tag=="-a") {
		
		AbstractFileVisitor* visitor = new BasicDisplayVisitor();
		file->accept(visitor);
		cout <<""<< endl;
		cout << "Please enter something to append to the file or ':wq' to save and quit, or ':q' to quit" << endl;
		string totalInput;
		string curInput;
		int res = start;
		//using a while loop to check for :wq and :q
		while (res == catCommandSuccess) {
			getline(cin, curInput);
			if (curInput.compare(quit) == start) {
				res = catQuit;
			}
			if (curInput.compare(saveQuit) == start) {
				res = catSaveandQuit;
			}
			totalInput += curInput + '\n';
			curInput = "";
		}

		//if quitting without saving
		if (res == catQuit) {
			fileSystem->closeFile(file);
			return catCommandSuccess;
		}
		//if saving and quitting
		else if (res == catSaveandQuit) {
			//return an error if they try to append an image 

			if (fileName.substr(fileName.find(".")).compare(".img") == start) {
				fileSystem->closeFile(file);
				return invalidCatCommand;
			}
			//checking if there needs to be a chop
			else if (totalInput.size() > length) { 
				//make string into vector of chars
				vector<char> vect(totalInput.length() - length); 
				//Removes the \n:wq\n
				copy(totalInput.begin(), totalInput.end() - length, vect.begin()); 
				//checking for success in appenidng
				if (file->append(vect) == successful) {
					fileSystem->closeFile(file);
					return catCommandSuccess;
				}
				else {
					return invalidCatCommand;
				}
			}
			return invalidCatCommand;
		}
	}


	else {
		cout << "Please input what you want to write to the file, ':wq' if you want to save and quit, or ':q' to quit without saving" << endl;
		
		string userInput;
		string currentLine;
		unsigned int res = catCommandSuccess;

		while (res == catCommandSuccess) { 

			getline(cin, currentLine);
			
			if (currentLine.compare(saveQuit) == start) {
				res = catSaveandQuit;
			
			}
			else if (currentLine.compare(quit) == start) {
				res = catQuit;
		
			}

			//if input is neither, clear the line
			userInput += currentLine + "\n";
			currentLine.clear();
		}

		
		if (res == catQuit) {
			fileSystem->closeFile(file);
			return catCommandSuccess;
		}

		//if saving and quitting
		if (res == catSaveandQuit) {
			//if user wrote something, we will check tosee if it is greater than length
			if (userInput.size() > length) { 
				//chopping off the length if it is greater than what we want
				vector<char> vect(userInput.length() - length); 
				//copying things over
				copy(userInput.begin(), userInput.end() - length, vect.begin()); 
				//check to see if we were successfully able to write to the file
				if (file->write(vect) == successful) {
					fileSystem->closeFile(file);
					return catCommandSuccess;
				}
				else {
					fileSystem->closeFile(file);
					return invalidCatCommand;
				}
				//otherwise we want to return an error
				fileSystem->closeFile(file);
				return invalidCatCommand;
			}
			return invalidCatCommand;
			
		}
	}

	fileSystem->closeFile(file);
	return invalidCatCommand;
}
