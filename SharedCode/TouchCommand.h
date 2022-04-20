#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
class TouchCommand : public AbstractCommand{
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	void displayInfo();
	int execute(std::string);

private:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
};