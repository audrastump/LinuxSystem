Studio 20 ReadMe.txt

2) If you don't have a file with a password, you don't want a file at all because it is unsafe. Also, it is important because the pointer is dynamically
allocted so we need to delete it with a destructor since it is not going to be deleted by main

3) None

4) It all worked!
	We created a Password Proxy which we read and wrote from. We ensured that the password checker worked and we checked that the files could 
	be written to.
	Heres some code from our tests: 
	AbstractFile* f = new TextFile("file.txt");
	string password = "key";

	PasswordProxy* p = new PasswordProxy(f, password);
	vector<char> v = { 'h', 'e','l','l','o'};

	//valid password
	cout << pp->write(v) << endl;

	cout << (v.size()) << " = " << realfile->getSize() << endl;

	cout << pp->read().size() << endl;

	return 0;

5) Unit tests pass