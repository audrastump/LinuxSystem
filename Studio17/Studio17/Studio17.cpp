// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <vector>
#include <iostream>
#include "..\..\\SharedCode\ImageFile.h"

int main()
{
	ImageFile i("image1");
	vector<char> v = { 'X', 'X', 'X', 'X', 'X', 'X', 'X','X', 'X', '3' };
	i.write(v);
	std::cout << i.getName() << endl;
	std::cout<< i.getSize()<<endl;
	i.read();


}

