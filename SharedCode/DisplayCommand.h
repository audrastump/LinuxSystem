#pragma once
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