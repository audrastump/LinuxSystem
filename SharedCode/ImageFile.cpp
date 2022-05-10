/*
* Audra Stump and David Buckley
* Lab 5 - CSE 332
* ImageFile.cpp
* Contains the definitions for the ImageFile class which returns the image file's name, size, allows a user to write, read, accept, clone, and returns an
* error if the user tries to append to it
*/
#include "ImageFile.h"
#include <iostream>
using namespace std;
//our constructor initializes the name and size 
ImageFile::ImageFile(std::string n): name(n), size(start) {}
//returns size
unsigned int ImageFile::getSize() {
	return static_cast <int>(contents.size());
}
//returns the image's name
std::string ImageFile::getName() {
	return this->name;
}

int ImageFile::write(vector<char> vect) {
	//if the vector has nothing in it we want to set the size to 0 and clear our contents
	if (vect.size() == start) { 
		size = start;
		contents.clear();
	}
	//turning our dimensions into char form
	char dimensions = vect[vect.size() - 1] - '0';    
	//if the dimensions is greater than zero and the dimensions squared equals the size-1 we want to proceed
	if (dimensions >= start && dimensions * dimensions == vect.size() - 1) {
		contents.clear();
		//iterating through our vector
		for (size_t index = start; index <= vect.size() - 2; ++index) {
			//pushing back things based off of what is in them
			if (vect[index] == ' ') {
				contents.push_back(' ');
			}
			else if (vect[index] == 'X') {
				contents.push_back('X');
			}
			else {
				//we don't want to push back anything that isn't a space or an X
				size = start;
				contents.clear();
				return invalidImage;
			}
		}
		//the size will be the dimensions
		size = dimensions;
		return successful;
	}
	else {
		//otherwise we want to clear our image and return an error number
		size = start;
		contents.clear();
		return sizeDoesntMatch;
	}
}
//cannot append to an image, automatically return an error
int ImageFile::append(std::vector<char> image) {
	return errorAppending;
}
//read from an image
std::vector<char> ImageFile::read() {
	return this->contents;

}
//using accept to call the visitor pattern on the image file
void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_ImageFile(this);
}
//creating a new cloned file and writing what the read returns from this file
AbstractFile* ImageFile::clone(string name) {
	AbstractFile* clonedFile = new ImageFile(name);
	vector<char> clone = this->read();
	int s1 = trunc(sqrt(this->getSize()));
	char s = s1 + '0';
	clone.push_back(s);
	
	clonedFile->write(clone);
	return clonedFile;
}