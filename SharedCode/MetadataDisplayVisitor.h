/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* MetaDataDisplayVisitor.h
* Contains the declarations for the MetaDataDisplayVisitor class
*/
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
