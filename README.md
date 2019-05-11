# System Programming and Tools
---------------------------------------------------------------------------------------------------  
Project #1 [65 points]
---------------------------------------------------------------------------------------------------  
Attention! In the beginning of each program (Bash script file), after “shebang” line, there should be comments with the author’s name and the purpose of a script. Up to 3 points will be subtracted from your score for each part of the project if you don’t include this information.
### A.	[30 points] Write a Bash shell script named info.sh. The command for execution must include two command-line parameters: the name of the file that will be displayed and the name of the directory the listing of which you want to obtain. The output of this script must contain the following information:
- The name of your script;
- “Usage” message (what should be typed to execute your file);
- Current date and time;
- The name of the user;
- The name of current working directory;
- The name of UNIX machine;
- The name of login shell;
- Contents of the required file;
- Number of text lines in the file;
- Listing of the required directory;
- Total number of parameters of the script;
- Calendar for October of the current year;
- Disk usage;
- Current number of users in the system;
- Current time.
##### Important: 
1) make sure that in the beginning of your script you include information about a shell that will execute your script and the ‘usage’ line; 
2) check the number of parameters and their types in the beginning of the script; if requirements are not met exit with a non-zero status; 
3) each portion of the output must be preceded with some clarifying information; 
4) use manual pages to study commands that you will need in your script and that were not discussed in the class (possibly, du, cut, date with specific options).

----

### B.	[20 points] Write a Bash shell script factor.sh  that will do the following: 
1) it prompts a  user to enter an integer n from 10 to 100; 
2) Find the smallest (prime) factor for that number, so if the number is 21, it would output the message “The smallest factor is 3”. If the number was 77, it would output “The smallest factor is 7”. 
3) If the number has no factors other than itself, it should output “This number is prime”.  

----
### C.	[15 points] Write a Bash shell script testaverager.sh that will determine if a person has passed a class. It should take in as a command-line parameter a name (first and last name) as well as a series of numbers. This list could be of any length. Your script should start by calculating the average of the scores. If the result is below 70, it should output “Sorry [name] but you will have to retake the class!”. If the result is 70 or greater, congratulation the student with some message about succeeding at the class. 

##### Sample Output:
Mary Jones 82.5 78.3 86.0   
Congratulations Mary Jones, you passed with an average of 82!
 

---------------------------------------------------------------------------------------------------  
Project #2 [65 points]
---------------------------------------------------------------------------------------------------  
### A. [20 points] Write a script named listEmptyDir.sh that will do the following: (a) take a name of a directory as a parameter; (b) loop through all files in this directory and display their names; (c) if a file is a directory and has no files in it (empty directory), add the name of this empty directory to the file EmptyDir.txt in your current directory. If the number of parameters is not 1 or a parameter is not a directory, display the “usage” message and exit with non-zero status. Your file for submission should demonstrate that you have investigated all possible situations.

### B. [25 points] Transform a script contact_one.sh (sec. 5.2) so that instead of using a file with names it will use a HERE document (it may include the same information as the file myContactlist). Another change is that instead of using a positional parameter you read a pattern from a user (don’t forget about a prompt). Include a command grep into a while or until loop providing different input strings. If a name is not in HERE document, display a message saying that.
A HERE document is a way to add input to a script easily. It is described in section 5.17 of our textbook, page 144 in my copy. I have uploaded a copy of contact_one.sh

### C. [20 points] For this part, include a text document with the regular expressions for some sed calls that would do the following tasks:
1) Remove any uppercase or lowercase version of my initials (MWH) from a document and replace them with MRH.
2) Write a regular expression that would match any file in ending in .jpg
2a) Using the above regular expression, use sed to replace that extension with the extension .jpeg
3) Give a sed command that would output every line in a file that did not start with the letter ‘a’ and do not end with .html
4) Write a line in sed to find all phone numbers that look like 1234567890 with (123)456-7890


--------------------------------------------------------------------------------------------------- 
Project #3 [40 points]
---------------------------------------------------------------------------------------------------  
### A.	[20 points] Write a program that takes its command-line arguments and starts by printing them in reverse order.  For example, if your executable is called reverse and you run it by:
./reverse one two three
The output should be:
	three two one
### B.	[20 points] Adding to your program in part A, go through the command line arguments and find the largest and smallest arguments (by lexographic order). Note that you should not need to sort your arguments, but instead compare them and save the smallest and largest strings as you go through. For example, if called with ./reverse one two three:
It would display the output for part A:<br>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Three two one<br>
And then it would display<br>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The smallest string was: one<br>
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The largest string was: two	

--------------------------------------------------------------------------------------------------- 
Project #4 [60 points]
---------------------------------------------------------------------------------------------------   
### Task:
In this project you are being asked to write a program that will read in a text file based on a command line argument and then work with that file, producing an output file.
The command line arguments that your program should take are -h, -i and -o. -i lets the person running specify the input file (default should be input.txt). -o lets the user specify the output file (default should be output.txt). 

An example of running this project would be, if your executable was called palin,
./reverser -i data.in -o data.out
	to read data from the file data.in and send data to data.out

The input file will consist of many lines of numbers, separated by spaces, with no line longer than 80 characters. An example input file would be something like this:
5 17 20 37 8
57 17 17 5 3 9
1 2 3 4 5 6
7 8 1 837 43847

I want you to go through this file, line by line. Starting with the first number, read it number by number into a stack data structure that you create. This stack should be implemented using a structure, with a fixed or dynamically allocated array and an integer storing the location of the topmost element and appropriate functions that work with that structure (push, pop). An example of this structure would be something similar to:
struct Stack {
    int top;
    int stack[100];
};

Then, using that stack, output the numbers to your output file, again line by line. Treat each line separately. The result should be a file where each output line is the reverse of the input line, with one condition. I want your stack functions to ignore duplicates. So your stack should, before adding an element to the stack, ensure that the number is not already in the stack.

#### Details:
You must implement this project using at least 3 source files, reverser.c, stack.h, stack.c, You also must have a makefile that will compile the project for me. If you do not include a makefile your project will not be run.

In addition, I want you to take a screenshot of you using the debugger to examine the elements of your stack array in the middle of running your code. That is because I want you to immediately start using the debugger and so this is part of your credit.

#### Submission:
Submit the 3 source files, your makefile, and the proof of debugging as separate files in canvas (not zipped up please). 


---------------------------------------------------------------------------------------------------  
Project #5 [60 points]
---------------------------------------------------------------------------------------------------  
### Task:
In this project you are writing a program that will create some shared memory and then launch a user process (using fork and exec) to do some work. The user process and the master process will very briefly communicate and then they both will terminate. The point of this project is to test launching, execing and basic shared memory usage. Doing this project’s task without using the appropriate system calls will result in virtually no credit. Examples of shared memory using multiple processes (though not of fork/exec) can be found at /accounts/facstaff/hauschildm/scripts/C/shm/t


In particular, your project will involve 2 executables, worker and master, with a makefile that should compile both of them. You will need to use the all target to do so (to make both of those executables) as described in class. When master launches, it should take in two possible command line arguments, -h and -n. -h would simply output what command line arguments we take. -n will be followed by a number, so for example a possible call would be:
./master -n 99

If -n is not used, then it should default to 100.

Master should start by allocating a shared memory region to hold an integer. It should then set that shared memory location to 0. (Make sure and set the shared memory before doing any of the following fork/exec). Then it should do a single fork() (Do not do this in a loop). This fork should be followed by code that determines if it is the parent or child. The child should immediately exec the worker executable, giving it as a command line argument the parameter passed as -n (or the default value). Master should then continually look at the shared memory location, waiting for it to become any other value than 0. Once it changes, it should print that value to the screen, then set the shared memory value back to 0 and then wait for the child to end.

When the user process is launched, it should take its command line argument given to it and try and find the largest prime smaller than it. So for example, if given 99, it should find the prime 97. It should then attach to shared memory, and see if a 0 is there in shared memory. If that shared memory is not set to 0, it should output an error message and terminate. If it sees a 0, it should output a message indicating it saw a zero. Then it should set that shared memory location to the value of the prime that we found (in this case, 97). Then the user process should, in a loop, check to see when the memory location gets set back to 0. When it does, it should output a message to screen indicating that the memory location was reset back to 0. Then it should terminate.
Note that all output should indicate whether it is output from master or worker.

As the master is doing a wait for the child to end, it should then end after it detects that the child ended, outputting a message indicating that it is terminating because the child is terminating.
Before terminating, make sure to free up your shared memory.
Details:
This project must involve two executables. It must use shared memory to communicate. There should be a single makefile that compiles both of them. Points will be taken off if your project leaves shared memory in the system after running.

To check on shared memory, you can use the command as discussed in class, ipcs. To manually remove a shared memory assigned to you, you use the command ipcrm, giving it appropriate command line options. 

In addition, I expect you to use local version control. I want your project to be committed at least 3 times, with differing stages of tasks done and appropriate commit messages. This is worth 10% of your credit and is the easiest part. Do not skip this.

#### Hints:
Do this process incrementally, testing as you go, and it should go fairly quickly. One way to do this would be:
##### 1)	Write a master that takes in appropriate command line arguments and a worker that takes in a number (as well as a makefile for them both). Have each just verify and output the results. Then test them manually by calling separately.
##### 2)	Have master fork off and then exec worker, then waiting for it to end, passing it its number. Test that this passing worked correctly.
##### 3)	Write the code for the worker, given a number, to find the prime lower than it, should be easiest part!
##### 4)	Have master allocate shared memory and set it to some nonzero value and then see if child sees that value, have it output that value. This is to test if the shared memory is set up correctly.
##### 5)	Lastly, start having them communicate using the shared memory.


#### Submission:
Submit the 2 source files, the output of your git log as text input (or a separate text file) and your makefile as separate files in canvas (not zipped up please). 
