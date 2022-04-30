#pragma once
/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* CopyCommand.h
* Contains the declarations for the CopyCommand class which inherits publicly from AbstractCommand and has a constructor,
* execute, and displayInfo method
*/
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "BasicDisplayVisitor.h"
#include "AbstractFile.h"
#include <string>
#include <iostream>
class CopyCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;

public:
	CopyCommand(AbstractFileSystem* afs);
	virtual int execute(std::string name) override;
	virtual void displayInfo() override;
	
};