#pragma once
/*
* Audra Stump and David Buckley
* Lab 5 - CSE 332
* MacroCommand.cpp
* Contains the definitions for the MacroCommand class which will allow us to construct commands out of other commands
* It inherits from AbstractCommand interface and contains a pointer to an abstract parsing strategy interace
*/
#include "MacroCommand.h"
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
using namespace std;
//initializing al our macrocommand things 
MacroCommand::MacroCommand(AbstractFileSystem* afs) : fileSys(afs), pStrat(nullptr) {}

//executing macrocommand
int MacroCommand::execute(std::string command) {
	//creating a vector that represents the result of parsing
	vector<string> commandParams = this->pStrat->parse(command);
	int count = start;
	//iterating through all the commands in the command list
	for (const auto& command : this->commandList) {
		//if executing the command at each cout is not successsful
		if (command->execute(commandParams[count]) != successful) {
			//return an error in the macrocommand
			return errorMacroCommand;
		}
		//move the command up one 
		++count;
	}
	return successful;

}
//pushing the command to our command vector 
void MacroCommand::addCommand(AbstractCommand* command) {
	commandList.push_back(command);
}
//setting our parse strategy to the input
void MacroCommand::setParseStrategy(AbstractParsingStrategy* curAPS) {
	this->pStrat = curAPS;
}
//usage message
void MacroCommand::displayInfo() {
	
	cout << "Please enter 'mc' and your commands separated by a semicolon." << endl;
}
