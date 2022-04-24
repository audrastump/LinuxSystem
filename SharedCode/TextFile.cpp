//  Define the TextFile class here
#include "TextFile.h"
#include <string>
#include <iostream>
using namespace std;
//defining constructor for TextFile
	TextFile::TextFile(std::string s) {
		fileName = s;
	}
	
	vector<char> TextFile::read() {
		
		return contents;
		
	}
	unsigned int TextFile::getSize() {
		return (unsigned int)contents.size();
	}
	int TextFile::write(std::vector<char> input) {
		
		contents = input;
		return 0;
		
	}
	int TextFile::append(std::vector<char> input) {
		
		for (auto it = input.begin(); it != input.end(); it++) {
			this->contents.push_back(*it);
		}
		
		return 0;
	}
	
	std::string TextFile::getName() {
		return fileName;
	}
	//takes in pointer and visits the text file
	void TextFile::accept(AbstractFileVisitor* vis) {
		if (vis) {
			vis->visit_TextFile(this);
		}
	}
