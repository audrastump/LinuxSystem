// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
void MetadataDisplayVisitor::visit_TextFile(TextFile* textFile) {
	std::cout<<textFile->getName()<<std::endl;
	std::cout << textFile->getSize() << std::endl;
	std::cout << "txt" << std::endl;
	
}
//visits the image file
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imageFile) {
	std::cout << imageFile->getName() << std::endl;
	std::cout << imageFile->getSize() << std::endl;
	std::cout << "image" << std::endl;
}