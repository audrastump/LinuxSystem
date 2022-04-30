#include "PasswordProxy.h"
#include <iostream>
using namespace std;
//constructor that initilializes the file and its password 
PasswordProxy::PasswordProxy(AbstractFile* file, string passwordFile) : file(file), passwordFile(passwordFile) {}
//destructor for deleting the file 
PasswordProxy::~PasswordProxy() {
	delete file;
}

string PasswordProxy::passwordPrompt() {
	string passwordInput;
	cout << "Please enter the password for this file " << endl;
	getline(cin, passwordInput);
	return passwordInput;
}

bool PasswordProxy::passwordMatches(std::string passwordInput) {

	return !(passwordInput.compare(passwordFile));
}

vector<char> PasswordProxy::read() {
	vector<char> vect;
	
	if (passwordMatches(passwordPrompt())) {
		return file->read();
	}
	else {
		//returns empty vector if it doesn't match 
		return vect;
	}
}

int PasswordProxy::write(vector<char> vect) {
	if (passwordMatches(passwordPrompt())) {
		return file->write(vect);
	}
	else {
		return passwordMismatch;
	}
}

int PasswordProxy::append(vector<char> vect) {
	if (passwordMatches(passwordPrompt())) {
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



void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	if (passwordMatches(passwordPrompt())) {
		file->accept(visitor);
	}
}


AbstractFile* PasswordProxy::clone(string name) {

	//new abstract file
	AbstractFile* f = file->clone(name);

	//creating password for file
	AbstractFile* clonedAF = new PasswordProxy(f, passwordFile);

	return clonedAF;
}
