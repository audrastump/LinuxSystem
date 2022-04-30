#pragma once
/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* DisplayCommand.h
* Contains the declarations for the DisplayCommand class which inherits publicly from AbstractCommand and has a constructor, 
* execute, and displayInfo method
*/
#include "AbstractFile.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
class DisplayCommand : public AbstractCommand {
public:
	DisplayCommand(AbstractFileSystem* afs);
	virtual int execute(std::string name) override;
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSys;
};