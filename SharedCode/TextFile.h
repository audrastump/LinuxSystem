#pragma once
#include "AbstractFile.h"
// TextFile declaration goes here
class TextFile: public AbstractFile {
	
	/*
	Declare and define a constructor for the TextFile class that takes a single parameter, a
std::string, and uses it to initialize the name member variable of your class.*/
public:
	TextFile::TextFile(std::string s);
	virtual std::vector<char> read();
	virtual int write(std::vector<char> input);
	virtual int append(std::vector<char> input);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual void accept(AbstractFileVisitor* a) override;
private:
//private instance variables of the contents and fileName
	std::vector<char> contents;
	std::string fileName;

};