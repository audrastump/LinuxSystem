#pragma once
// Image file class declaration here
#include "AbstractFile.h"

class ImageFile : public AbstractFile {
	std::string name;
	std::vector<char> contents;
	char size;
	
public:
	void read();
	ImageFile(std::string n);
	unsigned int getSize();
	std::string getName();
	int write(std::vector<char> img);
	int append(std::vector<char> img);
	
};