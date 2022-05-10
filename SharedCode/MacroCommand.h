#pragma once
/*
* Audra Stump and David Buckley
* Lab 5 - CSE 332
* MacroCommand.h
* Contains the declarations for the MacroCommand class which will allow us to construct commands out of other commands
* It inherits from AbstractCommand interface and contains a pointer to an abstract parsing strategy interace
*/
#include "AbstractCommand.h"
#include "AbstractFile.h"
#include "AbstractParsingStrategy.h"

class MacroCommand : public AbstractCommand {
public: 
	MacroCommand(AbstractFileSystem* afs);
	virtual void addCommand(AbstractCommand* command);
	void setParseStrategy(AbstractParsingStrategy* aps);
	virtual int execute(std::string s);
	virtual void displayInfo() override;
private:
	AbstractParsingStrategy* pStrat;
	std::vector<AbstractCommand*> commandList;
	AbstractFileSystem* fileSys;
};