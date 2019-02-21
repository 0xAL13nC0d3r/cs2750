#!/bin/bash
factor=1

clear
echo "Enter a number between 10 and 100: "
read number

#I'm worried this may not run on graders machine the same way
if [[ $number -gt 100  ||  $number -lt 10 ]];then
	echo 
	echo "You didn't enter a number in the correct range! Try again!"
	exit
fi

for (( i=$number; i>1; i-- ))
do
	if [ $(( $number % $i)) -eq 0 ];then
		factor=$i
	fi
done

if [ $factor -eq 1 ];then
	echo
	echo "This number is prime"
	exit
else
	echo
	echo "The smallest factor is ${factor}" 
	exit
fi





  
