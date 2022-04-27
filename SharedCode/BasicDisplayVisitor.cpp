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
	for (double i = sqrt(v.size()); i >= start; --i) {
		for (double j = start; j < sqrt(v.size()); ++j) {
			int index = static_cast <int>(sqrt(v.size()) * i + j);
			if (index < v.size()) {
				cout << v[index];
			}

		}
		cout << "" << endl;
	}
}



