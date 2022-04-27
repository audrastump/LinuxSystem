// definition of ImageFile class here
#include "ImageFile.h"
#include <iostream>
using namespace std;
ImageFile::ImageFile(std::string n): name(n), size(0) {}
unsigned int ImageFile::getSize() {
	return static_cast <int>(contents.size());
}
std::string ImageFile::getName() {
	return this->name;
}
int ImageFile::write(vector<char> v) {
	if (v.size() == start) { 
		size = start;
		contents.clear();
	}
	char dimensions = v[v.size() - 1] - '0';    
	if (dimensions >= start && dimensions * dimensions == v.size() - 1) {
		contents.clear();
		for (size_t index = start; index < v.size() - 1; ++index) {
			if (v[index] == 'X') {
				contents.push_back('X');
			}
			else if (v[index] == ' ') {
				contents.push_back(' ');
			}
			else {
				size = 0;
				contents.clear();
				return invalidImage;
			}
		}
		size = dimensions;
		return successful;
	}
	else {
		size = start;
		contents.clear();
		return sizeDoesntMatch;
	}
}

int ImageFile::append(std::vector<char> img) {
	return errorAppending;
}
std::vector<char> ImageFile::read() {
	return this->contents;

}
void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_ImageFile(this);
}
