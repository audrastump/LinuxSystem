/*
  Audra Stump and David Buckey
* Lab 5 - CSE 332
* RenameParsingStrategy.cpp
* Contains the definitions for the RenameParsingStrategy class which takes in a strng and returns a vector of strings
*/
#pragma once
#include "RenameParsingStrategy.h"
#include <sstream>
#include <iostream>
using namespace std;
//takes in an original name and creates a vector of strings 
vector<string> RenameParsingStrategy::parse(string name) {
	
	string originalName;
	string newName;
	//extracting the original name
	istringstream iss(name);

	iss >> originalName;

	//extracting the new name
	iss >> newName; 

	
	vector<string> renameArgs;
	//pushing back the orignal name then a space and then the new name
	renameArgs.push_back(originalName + " " + newName); 
	//pushing back the original name 

	renameArgs.push_back(originalName);
	//returning the vector of strings 
	return renameArgs;
}

void RenameParsingStrategy::displayInfo() {
	cout << "Rename parsing strategy renames a file and can be called by rn <original name> <new name> " << endl;

}
