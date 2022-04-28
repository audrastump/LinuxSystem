#pragma once
/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* RemoveCommand.h
* Contains the declarations for the RemoveCommand class which inherits from the AbstractCommand class
*/
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
//remove command class publicly inherits from abstract commands
//removes files with the provided name from the file system
class RemoveCommand : public AbstractCommand {
public:
	//constructor will take in a file System pointer
	RemoveCommand(AbstractFileSystem* fileSys);
	//virtual default destructor
	virtual ~RemoveCommand() = default;
	//overriding our displayInfo method
	virtual void displayInfo() override;
	//overriding our execute method
	virtual int execute(std::string name) override;
	
private:
	AbstractFileSystem* fileSys;
};