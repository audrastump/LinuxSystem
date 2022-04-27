#pragma once
/*Audra Stump and David Buckley
* LS Command header file
* Contains declarations for the LS command class
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