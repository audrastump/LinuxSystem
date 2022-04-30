#pragma once
// Image file class declaration here
#include "AbstractFile.h"
#include <vector>
class ImageFile : public AbstractFile {
	std::string name;
	std::vector<char> contents;
	char size;

public:
	std::vector<char> read();
	ImageFile(std::string n);
	unsigned int getSize();
	std::string getName();
	int write(std::vector<char> img);
	int append(std::vector<char> img);
	//declaring accept interface to call the approproate visite method via pointer access
	virtual void accept(AbstractFileVisitor* a) override;
	virtual AbstractFile* clone(std::string name) override;
};