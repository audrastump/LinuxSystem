#pragma once
#include <map>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <string>
class CommandPrompt {
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*afs);
	void setFileFactory(AbstractFileFactory*aff);
	int addCommand(std::string, AbstractCommand*a);
	int run();
protected:
	void listCommands();
	std::string prompt();
private:
	std::map <std::string, AbstractCommand*> commMap;
	AbstractFileSystem* abFileSys;
	AbstractFileFactory* fileFact;

};
