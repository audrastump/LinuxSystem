/*
* Audra Stump and David Buckley
* Lab 5 - CSE 332
* BasicDisplayVisitor.cpp
* Contains the definitions for the BasicDisplayVisiotr class which will allow us to display the text files and image files
*/
#include "BasicDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile* textFile){
	//we will read in the file and then iterate through it using an iterator. Then we will print 
	vector<char> v = textFile->read();
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it; 
	}
}
void BasicDisplayVisitor::visit_ImageFile(ImageFile* imageFile) {
	//getting the size of the image file
	int size = imageFile->getSize();
	//reading in the file
	vector<char> file = imageFile->read();
	//our dimensions are going to be the square root of the size
	int dimension = static_cast<int>(sqrt(size));
	for (int i = start; i < size; ++i) {
		//if i is at a dimension point and it isn't zero then we want to create a new line
		if ((i % dimension == start && (i != start))) {
			cout << "" <<endl;
		}
		//then we will print out what is at i
		cout << file[i];
	}
	//new line each time 
	cout << endl;
}