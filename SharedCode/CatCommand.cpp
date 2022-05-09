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
//constructor initializes our file system variable
CatCommand::CatCommand(AbstractFileSystem* afs) : fileSystem(afs) {}
void CatCommand::displayInfo() {
	cout << "Append file with 'cat' then the file name then '-a' or write the file with 'cat' then the file name" << endl;
}
int CatCommand::execute(std::string s) {
	//set up iss and parse input
	istringstream iss(s);
	string fileName;
	string tag;
	iss >> fileName;
	iss >> tag;
	string quit = ":q";
	string saveQuit = ":wq";

	AbstractFile* file = fileSystem->openFile(fileName);

	//if file couldn't be opened
	if (file == nullptr) {
		fileSystem->closeFile(file);
		return invalidCatCommand;
	}

	//check if appending
	if (tag.compare("-a") == start) {
		//first, print current contents
		AbstractFileVisitor* visitor = new BasicDisplayVisitor();
		file->accept(visitor);
		cout <<""<< endl;

		//instructions for user
		cout << "input data to append to the file, \":wq\" to save and quit, or \":q\" to quit without saving" << endl;

		string totalInput;
		string curInput;
		int res = start;

		while (res == catCommandSuccess) { //will be false at end of input
			//get input
			getline(cin, curInput);

			//check if quitting
			if (curInput.compare(saveQuit) == start) {
				res = catSaveandQuit;
			}
			if (curInput.compare(quit) == start) {
				res = catQuit;
			}

			//if input is neither
			totalInput += curInput + "\n";
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

			else if (totalInput.size() > length) { 
				//make string into vector of chars
				vector<char> vect(totalInput.length() - length); 
				//Removes the \n:wq\n
				copy(totalInput.begin(), totalInput.end() - length, vect.begin()); 
				if (file->append(vect) == successful) {
					fileSystem->closeFile(file);
					return catCommandSuccess;
				}
			}
			return invalidCatCommand;
		}
	}

	//if not saving and not quitting, we want to write the file
	else {
		cout << "Please input what you want to write to the file, ':wq' if you want to save and quit, or ':q' to quit without saving" << endl;

		string userInput;
		string currentLine;
		unsigned int res = catCommandSuccess;

		while (res == catCommandSuccess) { 

			getline(cin, currentLine);
			//checking to see what the user inputted
			if (currentLine.compare(saveQuit) == start) {
				res = catSaveandQuit;
			
			}
			else if (currentLine.compare(quit) == start) {
				res = catQuit;
		
			}

			//if input is neither, clear the line
			userInput += currentLine;
			userInput += "\n";
			currentLine.clear();
		}

		//if just quitting, close the file and return success
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
