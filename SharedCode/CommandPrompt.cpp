/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* CommandPrompt.cpp
* Contains the definitions for the CommandPrompt class which prompts the user to enter different commands 
*/
#include "CommandPrompt.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//constructor for command prompt which initializes our abstract file system and file factory
CommandPrompt::CommandPrompt(): abFileSys(nullptr), fileFact(nullptr) {

}//setting our afs 
void CommandPrompt::setFileSystem(AbstractFileSystem* afs) {
	this->abFileSys = afs;
}
//setting our aff
void CommandPrompt::setFileFactory(AbstractFileFactory* aff) {
	this->fileFact = aff;
}
//adding a command to our our map of commands

int CommandPrompt::addCommand(std::string s, AbstractCommand* ac) {
	//creating a new string and abstract command pointer pair
	std::pair<string, AbstractCommand*> newComm(s, ac);
	//inserting the new command pair into the map
	commMap.insert(newComm);
	return successful;
}

int CommandPrompt::run() {
	//prompting the user for input
	
	//if the user asks for help
	bool run = true;
	while (run) {
		string userInput = prompt();
		if (userInput.compare("help") == start) {
			cout << "No Problem. Here are your possible commands: ";
			listCommands();
			//return nonzero val
			
		}
		//if the user enters quit return nonzero val
		if (userInput.compare("q") == start) {
			return userQuit;
		}


		//check to see if one word
		bool single = true;
		//iterating through all userinput and seeing if there is any space anywhere
		for (unsigned int index = start; index < userInput.size(); ++index) {
			if (userInput[index] == ' ') {
				single = false;
			}
		}
		//if one word
		if (single == true) {
			//find the user input in the map
			auto newCommand = commMap.find(userInput);
			//if the new command is somewhere in the map
			if (newCommand != commMap.end()) {
				//we will see if the new command can execute
				int executionSuccessVal = newCommand->second->execute("");
				//if that works, return some nonzero value 
				if (executionSuccessVal == start) {
					
				}
				//otherwise output something 
				else {
					cout << "Command didn't work" << endl;
					
				}
			}
			//if the command didnt exist in the map
			else {
				cout << "Could not find command" << endl;
				
			}

		}
		else {
			//if the input is nonsingular
			istringstream iss(userInput);
			//extract the first word
			string firstWord;
			iss >> firstWord;

			//if the user asks for help
			if (firstWord.compare("help") == start) {
				//extract word 2
				string secondWord;
				iss >> secondWord;
				//find word 2
				auto newCommand = commMap.find(secondWord);
				if (newCommand != commMap.end()) {
					//display info for the specified command
					newCommand->second->displayInfo();
					//return that the user asked for help
					
				}
				else {
					//otherwise we just want to report that the command was not found
					cout << "Command not found." << endl;
					
				}

			}

			//we want to find the space then add one since we start at zero - this is where the prompt starts
			string comm = userInput.substr(userInput.find(' ') + 1);
			//creating an iterator to find the name
			auto newComm = commMap.find(firstWord);

			//if the iterator doesn't reach the end
			if (newComm != commMap.end()) {

				//executing the command name
				int executionSuccessVal = newComm->second->execute(comm);
				//if the execution was successful return a value indicating this
				if (executionSuccessVal == successful) {
					
				}
				else {
					//otherwise we want to report that we had an error executing the command and return the error value
					cout << "Error executing command" << endl;
					
				}
			}
			else {
				//return that the command was not found and return a value indicating that 
				cout << "Command not found" << endl;
				
			}


		}
	}
	return commandDidntWork;
	

}
//lists the commands
void CommandPrompt::listCommands() {
	//using iterator, iterates through command map and prints the first value for each command
	for (auto it = commMap.begin(); it != commMap.end(); ++it) {
		std::cout << it->first << std::endl;
	}
}
//prompts the user for the command
std::string CommandPrompt::prompt(){
	std::cout << "Please enter a valid command or ':q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command" << std::endl;
	std::cout << "$  ";
	std::string input;
	std::getline(std::cin, input);
	return input;

}

