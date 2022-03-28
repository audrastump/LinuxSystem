#pragma once
#include "AbstractFile.h"
// TextFile declaration goes here
class TextFile: public AbstractFile {
	
	/*
	Declare and define a constructor for the TextFile class that takes a single parameter, a
std::string, and uses it to initialize the name member variable of your class.*/
public:
	TextFile::TextFile(std::string s);
	void read();
	int write(std::vector<char> input);
	int append(std::vector<char> input);
	unsigned int getSize();
	std::string getName();
private:
	std::vector<char> contents;
	std::string fileName;

};