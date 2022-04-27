#include "CommandPrompt.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
CommandPrompt::CommandPrompt(): abFileSys(nullptr), fileFact(nullptr) {

}
void CommandPrompt::setFileSystem(AbstractFileSystem* afs) {
	this->abFileSys = afs;
}
void CommandPrompt::setFileFactory(AbstractFileFactory* aff) {
	this->fileFact = aff;
}
int CommandPrompt::addCommand(std::string s, AbstractCommand* ac) {
	std::pair<std::string, AbstractCommand*> newComm(s, ac);
	commMap.insert(newComm);
	return successful;
}
int CommandPrompt::run() {
	string userInput = prompt();
	if (userInput.compare("help") == start) {
		cout << "Possible commands: ";
		listCommands();
		return userHelp;
	}
	//if the user enters quit return nonzero val
	if (userInput.compare("q") == start) {
		return userQuit;
	}
	//if the user enters help return nonzero value
	

	//check to see if one word
	bool single = true;
	for (unsigned int index = start; index < userInput.size(); ++index) {
		if (userInput[index] == ' ') {
			single = false;
		}
	}
	//if one word
	if (single==true) {
		//find the user input in the map
		auto newCommand = commMap.find(userInput);
		//if the new command is not at the end
		if (newCommand != commMap.end()) {
			//we will see if the new command can execute
			int executionSuccessVal = newCommand->second->execute(""); 
			//if that works, return some nonzero value (need to change this )
			if (executionSuccessVal == start) {
				return executed;
			}
			//otherwise output something 
			else {
				cout << "Erronous command!" << endl;
			}
		}
		cout << "Could not find command" << endl;
		return cantFindCommand;
	}

	//if the input is nonsingular
	istringstream iss;
	iss.str(userInput);
	//extract the first word
	string word1;
	iss >> word1;

	//if help
	if (word1.compare("help") == start) {
		//extract word 2
		string word2;
		iss >> word2;
		//find word 2
		auto newCommand = commMap.find(word2);
		if (newCommand != commMap.end()) {
			//display info
			newCommand->second->displayInfo();
			//return successs
			return userHelp;
		}

		cout << "Could not find command" << endl;
		return cantFindCommand;
	}

	//get substring
	string comm = userInput.substr(userInput.find(' ') + 1);

	auto newComm = commMap.find(word1);
	if (newComm != commMap.end()) {
		int executionSuccessVal = newComm->second->execute(comm); //return execute's success or fail
		if (executionSuccessVal == start) {
			return executed;
		}
		else {
			cout << "Error executing command" << endl;
		}
	}
	cout << "Command not found" << endl;
	return cantFindCommand;

}

void CommandPrompt::listCommands() {
	for (auto it = commMap.begin(); it != commMap.end(); ++it) {
		std::cout << it->first << std::endl;
	}
}
std::string CommandPrompt::prompt(){
	std::cout << "Please enter a valid command or q to quit, help for a list of commands, or help<command name> for details about a specific command" << std::endl;
	std::cout << "$  ";
	std::string input;
	std::getline(std::cin, input);
	return input;

}

	std::map <std::string, AbstractCommand*> m;
	AbstractFileSystem* a;
	AbstractFileFactory* f;