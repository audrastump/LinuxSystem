// definition of ImageFile class here
#include "ImageFile.h"

ImageFile::ImageFile(std::string name): name(n), size(0){}
int ImageFile::getSize() {
	return this->contents.size();
}
std::string ImageFile::getName() {
	return this->name;
}
int ImageFile::write(std::vector<char> img) {
	int s = img.back() - 48;
	this->size = s;
	std::vector<char> v;
	for (auto it = img.begin(); it != img.end() -1; it++) {
		if (*it != "X" || *it != " ") {
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
