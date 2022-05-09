/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* PasswordProxy.cpp
* Contains the definitons for the PasswordProxy class 
*/
#pragma once
#include "PasswordProxy.h"
#include <iostream>
using namespace std;
//constructor that initilializes the file and its password 
PasswordProxy::PasswordProxy(AbstractFile* file, string passwordFile) : file(file), passwordFile(passwordFile) {}
//password prompt assks for the new password and returns it
string PasswordProxy::passwordPrompt() {
	string passwordInput;
	cout << "Please enter the password for this file " << endl;
	getline(cin, passwordInput);
	return passwordInput;
}

//reads the password proxy 
vector<char> PasswordProxy::read() {
	
	//if there is a correct keyword we will read the file
	if (correctKeyword(passwordPrompt())) {
		return file->read();
	}
	else {
		//returns empty vector if it doesn't match 
		vector<char> vect;
		return vect;
	}
}
//writes the file with the vector inserted as the parameter
int PasswordProxy::write(vector<char> vect) {
	//if the correct ckeyword, it will write the file
	if (correctKeyword(passwordPrompt())) {
		return file->write(vect);
	}
	else {
		//otherwise it will return an error
		return passwordMismatch;
	}
}
//appends the file with the vector parameter
int PasswordProxy::append(vector<char> vect) {
	//if there is a correct keyword, it appends
	if (correctKeyword(passwordPrompt())) {
		return file->append(vect);
	}
	else {
		return passwordMismatch;
	}
}
unsigned int PasswordProxy::getSize() {
	return file->getSize();
}
string PasswordProxy::getName() {
	return file->getName();
}
//accepts file if keyword is correct
void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	if (correctKeyword(passwordPrompt())) {
		file->accept(visitor);
	}
}
//clones file with name parameter
AbstractFile* PasswordProxy::clone(string name) {

	//new abstract file
	AbstractFile* f = file->clone(name);

	//creating password for file
	AbstractFile* clonedAF = new PasswordProxy(f, passwordFile);

	return clonedAF;
}
//checks to see if the correct keyword was inserted
bool PasswordProxy::correctKeyword(string passwordInput) {
	if (passwordInput.compare(passwordFile) == successful){
		return true;
	}
	else {
		return false;
	}
}