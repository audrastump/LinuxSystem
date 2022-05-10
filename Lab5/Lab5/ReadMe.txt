Lab 5 Readme

Audra Stump: Wrote some of the individaul methods including the MacroCommand, Touch Command, Remove, and LS Command. Mostly worked on getting
the unit tests to pass correctly for each of the methods

David Buckley: Wrote main method assisted in class with studios 16-21, helped debug issues with one of the commands and with the
command prompt, wrote the additional MacroCommand(Touch+Cat), helped fix an issue with copying imagefiles so that
they display after copy, worked on some formatting issues with ds and ls, ran tests and wrote readme.

METHODS AND TESTS: 
1) Entering a blank input will return that it cannot find the command. Similarly, entering a string of random letters, numbers, whitespace, or characters
also returned an error message. 
$  adsfadsfa
Please enter a valid command
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$

and 
$ (no input)
Please enter a valid command
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$

2) Entering the word "help" returns a list of the commands, each on different lines: 
$  help
No Problem. Here are your possible commands:
cat
cp
ds
ls
rm
rn
touch
touch+cat
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command

3) Entering the word help + any command returns a description of each of the commands: 
$  help ds
To display files, please enter command: ds 'file name' (-d)
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command

4) Ran test for ls and ls -m which yield expected results(two files per line for ls and file, file type, and metadata for ls -m). 
Also double checked that if ls + any invalid tag was entered, then it gave an error message 

For example, after adding a bunch of random inputs we got this when calling ls -m 
abcd.txt             text                 0
abcde.txt            text                 0
adf.txt              text                 0
asdadga.img          image                0
asdfasddsads.txt     text                 0
image1               image                9

This was expected, and all of the input is aligned correctly. 
When calling just ls on this same input : 
abcd.txt            abcde.txt
adf.txt             asdadga.img
asdfasddsads.txt    test.img

This is also expected. All of the input is aligned correctly. 

When trying to do ls -adsfsd or ls adfsasf (an invalid input), an error message (that we wrote) was displayed. This was correct since our program was able
to correctly catch this error. 

We also are able to password protect the metadata of the files
test2.txt is password protected and has password abc, so when entering the correct password we can view the metadata: 
$  ls -m
image1               image                9
test1.txt            text                 0
Please enter the password for this file
abc
test2.txt            text                 0
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
	
However, entering an incorrect password will block the user from seeing the metadata: 
$  ls -m
image1               image                9
test1.txt            text                 0
Please enter the password for this file
asdfsa
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command

5) rm removes file from the system so can no longer be displayed and doesn't show up in ls. If invalid filename entered returns
appropriate error code, and outputs "error executing command."

For example, if we started with this output when calling ls
abcd.txt            abcde.txt
adf.txt             asdadga.img
asdfasddsads.txt    test.img

Then calling : rm abcd.txt results in this output when calling ls afterwards: 

abcde.txt           adf.txt
asdadga.img         asdfasddsads.txt
test.img

When calling rm invalid.txt (whcih is not in the set of files) we get this error

File not found
Error executing command

Which is a good sign!

Also when calling rm with no file, we get:
No file entered to delete
Error executing command

Also, which is what we want. 

6) Touch creates files that do not use duplicate names. If file has duplicate name appropriate error code returned and output
message describes error. password protection also works user is prompted to create password and prompted for password 
on calls to cat and ds to this file. If touch + an invalid file is entered, it will return an appropriate error message 

For example: 
Starting with this set of files: 
$  ls
a.txt               ab.txt
abc.txt             abcd.txt
test.img
Doing touch abcde.txt results in 
$  ls
a.txt               ab.txt
abc.txt             abcd.txt
abcde.txt           test.img

Now, doing touch a.txt (a duplicate) results in 
Error executing command
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$
This is expected! We cannot create duplicate files. 

Now, lets try an invalid file name: 
$  touch dsafadsa
Error executing command
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command

Also, what we expected - user must include the extension when calling the touch command

We can also create a password protected file with touch 
$  touch abcdef.txt -p
Please enter the password
abcdef
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command

This is what we want: user is able to pick the password when they do the -p tag

Let's check if they enter an invalid tag: 

$  touch abcdasdfafd.txt dsaf
Error executing command
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command

This is also a good sign! We don't want them to enter an invalid tag and get away with it. 

7) Cat works as intended - if invalid filename entered command does not run and outputs message reflecting this. If cat is entered
user input replaces current input. if cat -a is called current file contents displayed and inputted text is appended. If :q
is typed no changes are made to current file contents and if :wq is written file contents are saved. Cat will continue to add whatever
the user types in until the user enters :q or :wq. Also, if the user types in cat + some invalid input or whitespace, the program catches the
error and prints an error message. Tested it with cat + an image file and it returned an error if we tried to append to it. Also checked that cat requires
the password before saving changes to a password protected file. 

For example: 
$  ls -m
image1               image                9
test1.txt            text                 0
//Lets now write to the file with the cat command
$  cat test1.txt
Please input what you want to write to the file, ':wq' if you want to save and quit, or ':q' to quit without saving
abcdefg
:wq
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  ls -m
image1               image                9
test1.txt            text                 7

This shows that the cat command correctly writes to the file when calling the :wq command. Let's try when just doing :q - 
$  ls -m
image1               image                9
test1.txt            text                 0
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  cat test1.txt
Please input what you want to write to the file, ':wq' if you want to save and quit, or ':q' to quit without saving
abcdefg
:q
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  ls -m
image1               image                9
test1.txt            text                 0
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$
As shown, the cat file does not save what is written when we call the :q during the cat function

Let's try the -a extension of the cat function: 
I first wrote abcdef to the test1.txt file, then called : cat test1.txt -a : 
input data to append to the file, ":wq" to save and quit, or ":q" to quit without saving
ghijklmnop
:wq
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  ls -m
image1               image                9
test1.txt            text                 16

As we can see, the function works and does not overwrite the orinal contents, it just appends onto them. 

We also need to enter the password to call cat on a password protected file: This code shows what happens if the password is incorrect
$  cat key.txt
Please input what you want to write to the file, ':wq' if you want to save and quit, or ':q' to quit without saving
abcd
:wq
Please enter the password for this file
dsafa
Error executing command

But if the password is correct: 
$  cat key.txt
Please input what you want to write to the file, ':wq' if you want to save and quit, or ':q' to quit without saving
abcdef
:wq
Please enter the password for this file
password
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  ds key.txt
Please enter the password for this file
password
abcdef

It works!
8) ds works as intended - invalid files dont display. Also works with images - test image file created in main as cat cant be used
to write image files; test image displays in 3x3 grid with ds and with ds-d it displays in a line.
For example: ds test.img returns 
XXX
XXX
XXX
and ds test.img -d returns XXXXXXXXX

It also works for text files: after writing abcdef to a test file it shows: 
$  ds test.txt
abcdef

ds dsafas returns : Error executing command  - as it should for an invalid file

Also checked that ds requires the password for a file - it prompts the user to enter the password before displaying the file. 
$  touch key.txt -p
Please enter the password
password
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  ds key.txt
Please enter the password for this file
pass

As shown above, the file will not be displayed if the password is not entered correctly
However, if the password is entered correctly
$  ds key.txt
Please enter the password for this file
password
abcd
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command

We can see that it works!

9) Cp works correctly - cannot copy files if the new file name already exists. it copies contents and for images maintains formatting
of the copied image.
For example: 

$  cp test.txt abc
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  ls
abc.txt             test.img
test.txt

Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  ls -m
abc.txt              text                 10
image1               image                9
test.txt             text                 10
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command

If I write to abc, it does not change the value of test, which is a good sign

Checked that if an image is copied, the ds command on the same image returns the same picture for each file
$  cp test.img copy
$  ds copy.img
XXX
XXX
XXX

10) Rn works correctly -  cant rename file to an existing name, and it appropriately copies and deletes original. Invalid filename
will not rename as intended.
For example: renaming a text file to a valid naem
$  ls
abc.txt             copy.img
key.txt             test.img
test.txt

Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  rn abc.txt def
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  ls
copy.img            def.txt
key.txt             test.img
test.txt

Trying to rename to an existing name: 
$  ls
12324.txt           copy.img
key.txt             test.img
test.txt

Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command
$  rn 12321.txt key
Error executing command

It doesn't work, as intended! 

11) touch+cat works correctly. If an already existing file, command does not work as intended, otherwise it will create the file
and immediately open the file editor. :q leaves file blank and :wq saves changes.
For example: 
$  touch+cat new.txt
Please input what you want to write to the file, ':wq' if you want to save and quit, or ':q' to quit without saving
abc
:wq
Either enter your command, 'q' to quit, 'help' for a list of commands, or 'help <command name>' for details about a specific command

Trying to create a file with the same name as the existing file
$  touch+cat key.txt
Error executing command

This throws an error as expected

Errors and Warnings: 

One warning in clone method of ImageFile caused by instantiating int to a double value. This is not a problem as the double
is truncated so it is essentially already an integer thus no data is lost as the warning suggests.

There was an error when doing touch + an invalid file, causing the program to crash. We fixed this by checking if the file contained a 
'.' substring, meaning it wouldn't try to create an AFP if it was an invalid file. 

There was another error where the "help" input kept causing the program to say "command not found". We fixed this by checking if the input
was equal to the help command and then only issueing a warning statement if it was not equal to it. 

There also was an issue where the ls command wouldn't be spaced out evenly. We fixed this by using setw(20), whcih was the maximum value that a name
could be to space them out. 