Lab 5 Readme

Audra Stump: Wrote some of the individaul methods including the MacroCommand, Touch Command, Remove, and LS Command. Mostly worked on getting
the unit tests to pass correctly for each of the methods

David Buckley: Wrote main method assisted in class with studios 16-21, helped debug issues with one of the commands and with the
command prompt, wrote the additional MacroCommand(Touch+Cat), helped fix an issue with copying imagefiles so that
they display after copy, worked on some formatting issues with ds and ls, ran tests and wrote readme.

METHODS AND TESTS: 
1) Entering a blank input will return that it cannot find the command. Similarly, entering a string of random letters, numbers, whitespace, or characters
also returned an error message. 

2) Entering the word "help" returns a list of the commands, each on different lines

3) Entering the word help + any command returns a description of each of the commands

4) Ran test for ls and ls -m which yield expected results(two files per line for ls and file, file type, and metadata for ls -m). 
Also double checked that if ls + any invalid tag was entered, then it gave an error message 
	
5) rm removes file from the system so can no longer be displayed and doesn't show up in ls. If invalid filename entered returns
appropriate error code, and outputs "error executing command."

6) Touch creates files that do not use duplicate names. If file has duplicate name appropriate error code returned and output
message describes error. password protection also works user is prompted to create password and prompted for password 
on calls to cat and ds to this file. If touch + an invalid file is entered, it will return an appropriate error message 

7) Cat works as intended - if invalid filename entered command does not run and outputs message reflecting this. If cat is entered
user input replaces current input. if cat -a is called current file contents displayed and inputted text is appended. If :q
is typed no changes are made to current file contents and if :wq is written file contents are saved. Cat will continue to add whatever
the user types in until the user enters :q or :wq. Also, if the user types in cat + some invalid input or whitespace, the program catches the
error and prints an error message.

6) ds works as intended - invalid files dont display. Also works with images test image file created in main as cat cant be used
to write image files; test image displays in 3x3 grid with ds and with ds-d it displays in a line.

cp works correctly cannot copy files if the new file name already exists. it copies contents and for images maintains formatting
of the copied image.

rn works correctly cant rename file to an existing name, and it appropriately copies and deletes original. Invalid filename
does not work as intended.

touch+cat works correctly. If an already existing file, command does not work as intended, otherwise it will create the file
and immediately open the file editor. :q leaves file blank and :wq saves changes.

Errors and Warnings: 

One warning in clone method of ImageFile caused by instantiating int to a double value. This is not a problem as the double
is truncated so it is essentially already an integer thus no data is lost as the warning suggests.

There was an error when doing touch + an invalid file, causing the program to crash. We fixed this by checking if the file contained a 
'.' substring, meaning it wouldn't try to create an AFP if it was an invalid file. 

There was another error where the "help" input kept causing the program to say "command not found". We fixed this by checking if the input
was equal to the help command and then only issueing a warning statement if it was not equal to it. 

