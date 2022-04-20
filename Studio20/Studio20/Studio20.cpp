// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include "../..//SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/TextFile.h"
#include <iostream>

using namespace std;

int main() {

	AbstractFile* realfile = new TextFile("file1.txt");
	string password = "key";

	PasswordProxy* pp = new PasswordProxy(realfile, password);
	vector<char> v = { 'h', 'e','l','l','o'};

	//valid password
	cout << pp->write(v) << endl;

	cout << (v.size()) << " = " << realfile->getSize() << endl;

	cout << pp->read().size() << endl;

	return 0;
}

