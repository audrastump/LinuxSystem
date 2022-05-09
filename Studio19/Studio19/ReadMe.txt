studio 19 answers here

1)

2) We created a text file called read on it and stored it into a vector and then we pushed back a new value and wrote back to the original
text file. This reflected the update to the contents, which is what we predicted. It also reflected an update to the size.

3) 
First you call accept on the concrete file and pass in the visitor function for that file type. This calls the visit function, which goes
to the respective file (either text or image), and calls functions (either getName() or getSize()) from the respective file. 

4) The function definitions are pushed to the visitor class which cleans up the concrete file classes which allwos for implementation of more 
methods using visitor classes. Delegation executes the text file member functions using the state of the visitor file. 

5) Every time that we add a new concrete file type we will need to modify the visitor design pattern to use these new concrete file types. Also we need
to make sure there is no circular inclusion occuring 

6) Tests pass
