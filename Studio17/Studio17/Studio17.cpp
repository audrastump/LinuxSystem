// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <vector>
#include <iostream>

#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
int main()
{
	ImageFile i("image1");
	vector<char> v = { 'X', 'X', 'X', 'X', 'X', 'X', 'X','X', 'X', '3' };
	i.write(v);
	std::cout << i.getName() << endl;
	std::cout<< i.getSize()<<endl;
	i.read();
	SimpleFileSystem s;

	AbstractFile* abstractfile = new ImageFile("rock");

	cout << "Name: " << abstractfile->getName() << endl;
	

	vector<char> v2 = { 'X',' ','X',' ','X',' ','X',' ', 'X', '3' };
	abstractfile->write(v2);
	abstractfile->read();
	cout << "Size: " << abstractfile->getSize() << endl;
	return 0;

}

