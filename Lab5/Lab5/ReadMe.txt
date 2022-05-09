Lab 5 Readme

Audra Stump

David Buckley: Wrote main method assisted in class with studios 16-21, helped debug issues with one of the commands and with the
command prompt, wrote the additional MacroCommand(Touch+Cat), helped fix an issue with copying imagefiles so that
they display after copy, worked on some formatting issues with ds and ls, ran tests and wrote readme.

Ran test for ls and ls -m which yield expected results(two files per line for ls and file, file type, and metadata for ls -m)

rm removes file from the system can no longer be displayed and doesn't show up in ls. If invalid filename entered returns
appropriate error code, and outputs "error executing command."

touch creates files that do not use duplicate names. If file has duplicate name appropriate error code returned and output
message describes error. password protection also works user is prompted to create password and prompted for password 
on calls to cat and ds to this file.

cat works as intended if invalid filename entered command does not run and outputs message reflecting this. If cat is entered
user input replaces current input if cat -a is called current file contents displayed and inputted text is appended. If :q
is typed no changes are made to current file contents and if :wq is written file contents are saved.

ds works as intended invalid files dont display. Also works with images test image file created in main as cat cant be used
to write image files; test image displays in 3x3 grid with ds and with ds-d it displays in a line.

cp works correctly cannot copy files if the new file name already exists. it copies contents and for images maintains formatting
of the copied image.

rn works correctly cant rename file to an existing name, and it appropriately copies and deletes original. Invalid filename
does not work as intended.

touch+cat works correctly. If an already existing file, command does not work as intended, otherwise it will create the file
and immediately open the file editor. :q leaves file blank and :wq saves changes.

One warning in clone method of ImageFile caused by instantiating int to a double value. This is not a problem as the double
is truncated so it is essentially already an integer thus no data is lost as the warning suggests.




