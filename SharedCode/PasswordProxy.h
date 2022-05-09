#pragma once
/*Audra Stump and David Buckey
* Lab 5 - CSE 332
* PasswordProxy.h
* Contains the declarations for the PasswordProxy class
*/
#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {

private:
	//private pointer to abstract file 
	AbstractFile* file;
	//private string (password for real file)
	std::string passwordFile;

protected:
	//passwordPrompt that returns a string 
	std::string passwordPrompt();
	//protected helper method that checks whether a string matches the password member varilabe 
	bool correctKeyword(std::string);

public:
	//constructor that takes in a poitner to the abstract file and the string representing the password for that file 
	PasswordProxy(AbstractFile* file, std::string passwordFile);
	//destructor that deletes the pointer to the real file 
	


	virtual int write(std::vector<char>) override;
	virtual std::vector<char> read() override;
	virtual int append(std::vector<char>) override;
	unsigned int getSize() override;
	std::string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string name) override;
	

};