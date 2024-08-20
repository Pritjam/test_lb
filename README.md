### Key aspects of the solution:

 - The file `trash` has been deleted 
 - The file `diff.log` has been created, and contains the differences between the factbook and `modified.txt`  
 - The file `identity.txt` has been created, and contains 1 line with the username of the student. 
 - The directory `writeup` has been created
 - In the `writeup` directory the file `differences.txt` has been created, and contains a short description of the difference between the factbook and the modified one. 
 - The `gitlog` file has been created and contains the git log printout

### How to autograde:

 - Check that the file `trash` doesn't exist 
 - Check that the file `diff.log` is correct (it should exactly match our reference)
 - Check that the file `identity.txt` has been created and contains 1 line of text (not just an empty file)
 - Check that the directory `writeup` has been created
 - Check that the file `differences.txt` has been created inside `writeup` (and not in the root dir!) and contains the string `teh` somewhere within it
 - Check that the file `gitlog` has been created (in the root dir!) and contains the key phrase Removed trash, identified differences". 

