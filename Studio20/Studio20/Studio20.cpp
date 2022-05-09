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

	AbstractFile* f = new TextFile("file1.txt");
	string password = "key";

	PasswordProxy* p = new PasswordProxy(f, password);
	vector<char> v = { 'h', 'e','l','l','o'};

	return 0;
}

