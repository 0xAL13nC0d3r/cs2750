#!/bin/bash
#Matt Cassell
#Write a Bash shell script to find the smallest prime factor for two integers give by the user.

clear
echo "Enter a number between 10 and 100: "
read number

if [[ $number -gt 100  ||  $number -lt 10 ]];then
	echo 
	echo "You didn't enter a number in the correct range! Try again!"
	exit
fi

factor=1
for (( i=$number; i>1; i-- ))
do
	if [ $(( $number % $i)) -eq 0 ];then
		factor=$i
	fi
done

if [ $factor -eq 1 ];then
	echo "This number is prime"
	exit
else
	echo "The smallest factor is ${factor}" 
	exit
fi





  
