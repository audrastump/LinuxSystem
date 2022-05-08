// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>

void MetadataDisplayVisitor::visit_TextFile(TextFile* textFile) {
	std::cout << textFile->getName() << " ";
	std::cout << "text" << " ";
	std::cout << textFile->getSize() << std::endl;
	
}
//visits the image file
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imageFile) {
	std::cout << imageFile->getName() << " ";
	std::cout << "image" << " ";
	std::cout << imageFile->getSize() << std::endl;
}