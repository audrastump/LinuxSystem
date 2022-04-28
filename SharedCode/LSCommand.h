#pragma once
/*Audra Stump and David Buckley
* Lab 5 - CSE 332
* LSCommand.h
* Contains declarations for the LS command class, including an execute command and a constructor and destructor
*/
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"

class LSCommand : public AbstractCommand {
	AbstractFileSystem* fileSystem;

public:
	LSCommand(AbstractFileSystem* afs);
	virtual int execute(std::string command) override;
	
	virtual ~LSCommand() = default;
};