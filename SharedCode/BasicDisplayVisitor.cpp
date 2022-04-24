// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
using namespace std;


void BasicDisplayVisitor::visit_TextFile(TextFile* textFile) {
	vector<char> v = textFile->read();
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it; 
	}
}
void BasicDisplayVisitor::visit_ImageFile(ImageFile* imageFile) {
	vector<char> v = imageFile->read();
	for (int i = sqrt(v.size()); i >= 0; --i) {
		for (int j = 0; j < sqrt(v.size()); ++j) {
			int index = sqrt(v.size()) * i + j;
			if (index < v.size()) {
				std::cout << v[index];
			}

		}
		std::cout << "" << std::endl;
	}
}



