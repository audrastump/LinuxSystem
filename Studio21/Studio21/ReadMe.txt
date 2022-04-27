Studio 21 ReadMe.txt 

2) So that all subclasses must have an implementation of a destructor and won't cause a memory leak

3) We can implement different concrete file systems and file types without having to modify our command prompt

4) We created a new simple file system and file factory then created a new touch command using those two objects. 
We then in a command prompt and within it create a file named fileTest. We called touch on fileTest and after quitting
it was still in our file system so we tested this by calling open file on our file test. 
	SimpleFileSystem* s = new SimpleFileSystem();
	SimpleFileFactory* sff = new SimpleFileFactory();
	TouchCommand* tc = new TouchCommand(s, sff);
	CommandPrompt* cp = new CommandPrompt();
	cp->setFileSystem(s);
	cp->setFileFactory(sff);
	cp->addCommand("touch", tc);
	cp->run(); 
	s->openFile("fileTest");
5) Unit tests pass