/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* CatCommand.h
* Contains the declarations for the CatCommand class which inherits publicly from AbstractCommand
*/
#pragma once
#include "AbstractCommand.h"
class CatCommand : public AbstractCommand {
	//constructor for cat command, takes in an abstract file system
public:
	CatCommand(AbstractFileSystem* afs);
	virtual int execute(std::string name) override;
	virtual void displayInfo() override;
private:
	AbstractFileSystem* fileSystem;


};
