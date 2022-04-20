// definition of ImageFile class here
#include "ImageFile.h"
#include <iostream>

ImageFile::ImageFile(std::string n): name(n), size(0){}
unsigned int ImageFile::getSize() {
	return this->contents.size();
}
std::string ImageFile::getName() {
	return this->name;
}
int ImageFile::write(std::vector<char> img) {
	int s = img.back() - 48;
	this->size =  img.back();
	std::cout << this->size << std::endl;
	std::vector<char> v;
	for (auto it = img.begin(); it != img.end() -1; it++) {
		if (*it != 88 && *it != 32) {
			return 1;
		}
		v.push_back(*it);
	}
	if (v.size() != s * s) {
		return 2;
	}
	this->contents = v;

	return 0;
}
int ImageFile::append(std::vector<char> img) {
	return 3;
}
std::vector<char> ImageFile::read() {
	return this->contents;

}
void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_ImageFile(this);
}
