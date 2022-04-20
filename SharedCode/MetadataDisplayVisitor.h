#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	//visits the text file
	virtual void visit_TextFile(TextFile* textFile);
	//visits the image file
	virtual void visit_ImageFile(ImageFile* imageFile);
};
