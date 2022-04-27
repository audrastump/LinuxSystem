studio 18 answers here
1) 

2) Using a factory for the file implementation is easier since the factory design pattern
creates objects using separate methods or polymorphic classes. This simplifies our methods for multiple file types and allows us to create
a related type polymorphically. 

3) A benefit is that you can override the implementation of functions polymorphically. A disadvantage would be that the type that is 
created matches the type that it must be used with. We would want to create a new file factory class when there are multiple similar objects
that we are working with. The code that we would modify would be the code in the SimpleFileSystem where we determine what the file type is. 
Yes the same file factory can be used if they use the same file types. If the systems manage different types of files
then we will need two different concrete file factory implementations. 

4) 
	We created a new textfile with the create file method from the file factory, named tester.txt. We then 
	wrote a vector of chars called <tester> to this textfile, and used the getName() method and result of the write method
	to added this file to the file system. We created a new abstractfile and set it equal to the results of opening a file with the name 
	of the previous text file. We then read this file and it returned "tester" as expected 

5) CreateFile was the only thing that depended on the concrete file types so now it is independent of it. 

6) Unit tests pass