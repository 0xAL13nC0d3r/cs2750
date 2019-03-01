#cs2750
##System programming and Tools Spring 2019
                                             #Project #1 [65 points]
---------------------------------------------------------------------------------------------------   
Attention! In the beginning of each program (Bash script file), after “shebang” line, there should be comments with the author’s name and the purpose of a script. Up to 3 points will be subtracted from your score for each part of the project if you don’t include this information.
#A.	[30 points] Write a Bash shell script named info.sh. The command for execution must include two command-line parameters: the name of the file that will be displayed and the name of the directory the listing of which you want to obtain. The output of this script must contain the following information:
•	The name of your script;
•	“Usage” message (what should be typed to execute your file);
•	Current date and time;
•	The name of the user;
•	The name of current working directory;
•	The name of UNIX machine;
•	The name of login shell;
•	Contents of the required file;
•	Number of text lines in the file;
•	Listing of the required directory;
•	Total number of parameters of the script;
•	Calendar for October of the current year;
•	Disk usage;
•	Current number of users in the system;
•	Current time.
Important: 
1) make sure that in the beginning of your script you include information about a shell that will execute your script and the ‘usage’ line; 
2) check the number of parameters and their types in the beginning of the script; if requirements are not met exit with a non-zero status; 
3) each portion of the output must be preceded with some clarifying information; 
4) use manual pages to study commands that you will need in your script and that were not discussed in the class (possibly, du, cut, date with specific options).

#B.	[20 points] Write a Bash shell script factor.sh  that will do the following: 1) it prompts a  user to enter an integer n from 10 to 100; 2) Find the smallest (prime) factor for that number, so if the number is 21, it would output the message “The smallest factor is 3”. If the number was 77, it would output “The smallest factor is 7”. 3) If the number has no factors other than itself, it should output “This number is prime”.  

#C.	[15 points] Write a Bash shell script testaverager.sh that will determine if a person has passed a class. It should take in as a command-line parameter a name (first and last name) as well as a series of numbers. This list could be of any length. Your script should start by calculating the average of the scores. If the result is below 70, it should output “Sorry [name] but you will have to retake the class!”. If the result is 70 or greater, congratulation the student with some message about succeeding at the class. 

Mary Jones 82.5 78.3 86.0   
Congratulations Mary Jones, you passed with an average of 82!
