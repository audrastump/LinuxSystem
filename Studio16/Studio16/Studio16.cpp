// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>


using namespace std;


int main(int argc, char* argv[])
{
	/*In the main function of your program (Studio16.cpp), create a variable of type “TextFile”.
Write to the file and try reading from the file as well as other tests to ensure the Text file
class is working as expected. As the answer to this question, describe the test cases you
ran and if your TextFile class behaved as expected.
	*/
	

	string s = "abcd";
	std::vector<char> v(s.begin(), s.end());
	string st = "name";
	AbstractFile* afPoint = new TextFile(st);
	
	afPoint->write(v);

	afPoint->read();

	cout<<afPoint ->getSize()<<endl;
	cout<<afPoint ->getName()<<endl;
	string s2 = "efgh";
	std::vector<char> v2(s2.begin(), s2.end());

	afPoint->append(v2);
	afPoint->read();

	delete afPoint;

	return 0;
}


