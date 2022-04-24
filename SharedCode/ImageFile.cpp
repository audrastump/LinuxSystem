// definition of ImageFile class here
#include "ImageFile.h"
#include <iostream>

ImageFile::ImageFile(std::string n): name(n), size(0) {}
unsigned int ImageFile::getSize() {
	return contents.size();
}
std::string ImageFile::getName() {
	return this->name;
}
/*
*/

/*int ImageFile::write(std::vector<char> img) {

	if (img.size() == 0) { // JS add to starter code
		size = 0;
		contents.clear();
	}
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
*/
int ImageFile::write(std::vector<char> vect) {
	unsigned int size = (vect.size()); // declare size of input vector
	char charsize = vect[size - 1]; // identify the last element of the vector
	size_t chartoint = static_cast<size_t>(charsize) - '0'; // convert the last element of the vector from char to int. warning here is ignored bc a character to size_t int cast is sufficient
	std::vector<char> contentvect(contents); // declare a new vector which will retain contents of the file
	contentvect.resize((chartoint * chartoint), 0); // resize the content vector to the size of the file declared in the input file
	if (size - 1 != contentvect.size()) {
		vect.clear();
		vect.resize(0, 0);
		// return non zero value for error
		return 3;
	}
	else {

		for (unsigned int i = 0; i < vect.size() - 1; i++) {
			if (vect[i] != 'X' && vect[i] != ' ') {
				vect.clear();
				vect.resize(0, 0);
				return 3;
			}
		}

		for (int i = 0; i < contentvect.size(); i++) {
			if (contentvect[i] != ' ' || contentvect[i] != 'X') {
				contentvect[i] = vect[i];
			}
			else {
				vect.clear();
				vect.resize(0, 0);
				return 3;
			}
		}
	}
	contents = contentvect;
	this->size = chartoint;
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
