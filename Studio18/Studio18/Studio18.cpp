// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/TextFile.h"
#include <iostream>

using namespace std;
using namespace std;

int main()
{
	AbstractFileSystem* fileSys = new SimpleFileSystem();
	AbstractFileFactory* fileFact = new SimpleFileFactory();

	

	AbstractFile* txtFile = fileFact->createFile("tester.txt");
	vector<char> tester = { 't', 'e', 's', 't', ' ','o','n','e'};
	txtFile->write(tester);
	fileSys->addFile(txtFile->getName(), txtFile);

	AbstractFile* ourFile = fileSys->openFile(txtFile->getName());
	ourFile->read();
	return 0;
}
