#pragma once
#include "RenameParsingStrategy.h"
#include <sstream>
#include <iostream>
using namespace std;

vector<string> RenameParsingStrategy::parse(string name) {

	string originalName;
	string newName;
	istringstream iss(name);

	iss >> originalName;
	iss >> newName; 

	
	vector<string> renameArgs;
	renameArgs.push_back(originalName + " " + newName); 
	renameArgs.push_back(originalName);
	return renameArgs;
}

void RenameParsingStrategy::displayInfo() {
	cout << "Renames a file and can be called by: rn <original name> <new name> " << endl;

}
