Studio 20 ReadMe.txt

2) If you don't have a file with a password, you don't want a file at all because it is unsafe

3) 

4) It all worked!
	AbstractFile* realfile = new TextFile("file1.txt");
	string password = "key";

	PasswordProxy* pp = new PasswordProxy(realfile, password);
	vector<char> v = { 'h', 'e','l','l','o'};

	//valid password
	cout << pp->write(v) << endl;

	cout << (v.size()) << " = " << realfile->getSize() << endl;

	cout << pp->read().size() << endl;

	return 0;
5) Unit tests pass