//  Define the TextFile class here
#include "TextFile.h"
#include <string>
#include <iostream>
using namespace std;
//defining constructor for TextFile
	TextFile::TextFile(std::string s) {
		fileName = s;
	}
	/*getSize returns the size of the vector<char> member variable

	*/
	void TextFile::read() {
		
		for (auto it = this->contents.begin(); it != this->contents.end(); it++) {
			cout << *it;
		}
		
		

	}
	unsigned int TextFile::getSize() {
		return this->contents.size();
	}
	int TextFile::write(std::vector<char> input) {
		//try {
			this->contents = input;
		/*}
		catch (...) {
			return 1;
		}
		
		*/
			return 0;
		
	}
	int TextFile::append(std::vector<char> input) {
		//try {
			for (auto it = input.begin(); it != input.end(); it++) {
				this->contents.push_back(*it);
			}
		//}
		//catch (...) {
		//	return 1;
		//}
		return 0;
	}
	
	std::string TextFile::getName() {
		return this->fileName;
	}
