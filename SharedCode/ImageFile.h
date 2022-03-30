#pragma once
// Image file class declaration here
#include "AbstractFile.h"

class ImageFile : public AbstractFile {
	std::string name;
	std::vector<char> contents;
	char size;
public:
	ImageFile(std::string n);
	int getSize();
	std::string getName();
	int write(std::vector<char> img);
};