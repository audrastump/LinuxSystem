#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	//visiting the text
	virtual void visit_TextFile(TextFile* textFile) override;
	//visits the image 
	virtual void visit_ImageFile(ImageFile* imageFile) override;
};
