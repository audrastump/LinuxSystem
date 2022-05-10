/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* MetaDataDisplayVisitor.h
* Contains the definitions for the MetaDataDisplayVisitor class
*/
// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
#include <iomanip>
//visits the textfile and prints the name and size
void MetadataDisplayVisitor::visit_TextFile(TextFile* textFile) {
	std::cout.width(maxInput);
	std::cout << std::left;
	std::cout << textFile->getName() << " ";
	std::cout.width(maxInput);
	std::cout << std::left;
	std::cout << "text" << " ";
	std::cout.width(maxInput);
	std::cout << std::left;
	std::cout << textFile->getSize() << std::endl;
	
}
//visits the image file and prints the name and size
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imageFile) {
	std::cout.width(maxInput);
	std::cout << std::left;
	std::cout << imageFile->getName() << " ";
	std::cout.width(maxInput);
	std::cout << std::left;
	std::cout << "image" << " ";
	std::cout.width(maxInput);
	std::cout << std::left;
	std::cout << imageFile->getSize() << std::endl;
}