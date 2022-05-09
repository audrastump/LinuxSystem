/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* TextFile.cpp
* Contains the definitions for the TouchCommand class which provides methods for reading, writing, getting the sieze, and the name of a text file
*/
#include "TextFile.h"
#include <string>
#include <iostream>
using namespace std;
//here is our constructor 
	TextFile::TextFile(std::string s) {
		fileName = s;
	}
	//this is pretty simple, just returning the contents member varialbe
	vector<char> TextFile::read() {
		
		return contents;
		
	}
	//returns the size, we cast it to an unsigned int
	unsigned int TextFile::getSize() {
		return (unsigned int)contents.size();
	}
	//changes the contents to the input vector and returns 0
	int TextFile::write(std::vector<char> input) {
		
		contents = input;
		return successful;
		
	}
	//creates an iterator, and looks through the contents, pushing back each of the items 
	int TextFile::append(std::vector<char> input) {
		
		for (auto it = input.begin(); it != input.end(); it++) {
			this->contents.push_back(*it);
		}
		//returns zero once it is done
		return successful;
	}
	//returns member variable for name
	std::string TextFile::getName() {
		return fileName;
	}
	//takes in pointer and visits the text file
	void TextFile::accept(AbstractFileVisitor* vis) {
		//if vis is not null
		if (vis) {
			//visiting the tesxt file with our new class
			vis->visit_TextFile(this);
		}
	}
	//clones the file that corresponds to the name passed in
	AbstractFile* TextFile::clone(string name) {
		AbstractFile* clonedFile = new TextFile(name);
		clonedFile->write(this->read());
		return clonedFile;
	}
