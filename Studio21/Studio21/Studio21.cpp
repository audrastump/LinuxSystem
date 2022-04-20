// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../..//SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include <iostream>
int main()
{
	SimpleFileSystem* s = new SimpleFileSystem();
	SimpleFileFactory* sff = new SimpleFileFactory();
	TouchCommand* tc = new TouchCommand(s, sff);
	CommandPrompt* cp = new CommandPrompt();
	cp->setFileSystem(s);
	cp->setFileFactory(sff);
	cp->addCommand("touch", tc);
	cp->run(); 
	s->openFile("fileTest");

}

