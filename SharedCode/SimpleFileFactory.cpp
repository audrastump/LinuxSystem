// studio 18 - simple file factory definitions
#include "TextFile.h"
#include "ImageFile.h"
#include "SimpleFileFactory.h"

using namespace std;

AbstractFile* SimpleFileFactory::createFile(string nameFile) {
	//extracting everything after and including the '.', which indicates the type of file 
	string afterDot = nameFile.substr(nameFile.find('.'));

	//if this is a text file
	if (afterDot.compare(".txt") == start) {
		//we want to create a new text file pointer and return 
		AbstractFile* txtFile = (new TextFile(nameFile));
		return txtFile;
	}

	//if this is an image file
	else if (afterDot.compare(".img") == start) {
		//create new image file
		AbstractFile* imgFile = (new ImageFile(nameFile));
		return imgFile;
	}

	//if neither, we will return a null pointer
	return nullptr;
}
