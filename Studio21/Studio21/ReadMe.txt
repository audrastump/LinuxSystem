Studio 21 ReadMe.txt 

2) Declaring a virtual destructor ensures that all subclasses must have an implementation of a destructor and won't cause a memory leak

3) We can implement different concrete file systems and file types without having to modify our command prompt. This is important  for the file system and file factor
because it allows us to recycle our code for different file systems that inherit from the base class

4) We created a new simple file system and file factory. Then we created a new touch command using those two objects. 
We then, in a command prompt, created a file named fileTest. We called touch command on fileTest. After quitting
it was still in our file system. We then called openFile on it just to make sure it still worked. 
Here is some code: 
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