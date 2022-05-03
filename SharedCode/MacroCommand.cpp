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
MacroCommand::MacroCommand(AbstractFileSystem* afs) : fileSys(afs), pStrat(nullptr) {}

int MacroCommand::execute(std::string command) {
	vector<string> commandParams = this->pStrat->parse(command);
	int count = start;
	for (const auto& command : this->commandList) {
		if (command->execute(commandParams[count]) != successful) {
			return errorMacroCommand;
		}
		count++;
	}
	return successful;

}
void MacroCommand::addCommand(AbstractCommand* command) {
	commandList.push_back(command);
}
void MacroCommand::setParseStrategy(AbstractParsingStrategy* curAPS) {
	this->pStrat = curAPS;
}
void MacroCommand::displayInfo() {
	cout << "Please enter 'mc' and your commands separated by a semicolon." << endl;
}
