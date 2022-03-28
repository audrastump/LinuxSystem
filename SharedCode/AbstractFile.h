#pragma once

// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>


#include <string>
class AbstractFile {
public:
	void read();
	int write(std::vector<char>);
	int append(std::vector<char>);
	unsigned int getSize();
	std::string getName();
};


