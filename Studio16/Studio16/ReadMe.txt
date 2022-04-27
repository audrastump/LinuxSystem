Answer studio 16 questions here


1) David Buckley and Audra Stump

2) An interface is a class with public member functions without definitions (pure virtual functions). This is declared by 
declaring the functions virtual in the header file and setting their values equal to zero, also in the header file. 

3a) This is interface inheritance. It inherits the interface but not the implementation. 
3b) These variables should be private 

4) We tried examining every function on the text file and every function worked. We wrote a vector of <'h','i'> to a text file and then 
named it "test". When calling getName() it returned test and when calling getSize() it returned 2. We also tried to append another vector
onto it, consisting of the chars in 'text' and this returned 'hitext', which is what we expected. 

5) Textfile was dynamically allocated and the AbstractFile pointer pointers to it
AbstractFile * afp = new TextFile("test")

6) Unit tests pass