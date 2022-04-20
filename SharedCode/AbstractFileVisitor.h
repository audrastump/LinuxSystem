#pragma once
// declaration of the file visitor interface here
class ImageFile;
class TextFile;


class AbstractFileVisitor {
public:
//visits the text file
	virtual void visit_TextFile(TextFile* textFile) = 0;
//visits the image file
	virtual void visit_ImageFile(ImageFile* imageFile) = 0;
};