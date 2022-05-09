#include "../SharedCode/TouchCommand.h"
#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/LSCommand.h"
#include "MetadataDisplayVisitor.h"
#include "AbstractFile.h"

#include <set>
#include <iostream>
#include <iomanip>



using namespace std;
//defining our constructor so that it initializes the AFS pointer to fileSystem
LSCommand::LSCommand(AbstractFileSystem* afs) : fileSystem(afs) {};
//so basically command will be the second word that the user types in
//since going to this class means that the user already typed in ls, 
//command will indicate whether there is a -m or not at the end of the sring
int LSCommand::execute(std::string command) {
	set<std::string> names = fileSystem->getFileNames();
	//if the user enters -m
	if (command == "-m") {
		//iterating through our set of names
		for (string fileName : names) {
			AbstractFileVisitor* vis = new MetadataDisplayVisitor();
			AbstractFile* f = fileSystem->openFile(fileName);
			f->accept(vis);
			fileSystem->closeFile(f);

		}
		
		return commandWorked;
	}
	//if there is no second word
	else if (command.empty()) {
		int count = first;
		for (string fileName : names) {

			cout << setw(maxInput) << " " << fileName;
			if (count == evenDivisor) {
				cout << "" << endl;
				count = first;
			}
			else {
				++count;
			}
		}
		cout << endl;
		return commandWorked;
	}
	else {
		return cantFindCommand;
	}
}
void LSCommand::displayInfo() {
	cout << "ls lists files in the directory" << endl;
}
