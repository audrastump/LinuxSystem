/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* TouchCommand.cpp
* Contains the definitions for the TouchCatParsingStrategy class which provides our combined macrocommand 
*/
#pragma once
#include "TouchCatParsingStrategy.h"
#include <sstream>
#include <iostream>
using namespace std;
//returns a vector and takes in a name of a string to parse
vector<string> TouchCatParsingStrategy::parse(string name) {

    
    string file;
   
    istringstream iss(name);
    iss >> file;
    vector<string> touchCatArgs;
    touchCatArgs.push_back(file);
    touchCatArgs.push_back(file);
    return touchCatArgs;
}

void TouchCatParsingStrategy::displayInfo() {
    cout << "This command creates a file and immediately starts to edit it. It is called with touch + cat <filename>" << endl;
}