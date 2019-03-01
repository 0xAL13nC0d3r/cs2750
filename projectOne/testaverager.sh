#!/bin/bash
#Matt Cassell
#Write a Bash shell script that will average test scores to determine a passing/failing grade.

clear
numberOfArguments=$#
declare -a scores
commandLineArray=( "$@" )

if [[ -z $1 || -z $2 || -z $3 ]];then
	echo "Usage: <first name> <last name> <test score> ..."
	exit
else 
	fname=$1
	lname=$2
	
	for (( i = 2; i <= $numberOfArguments; i++ ))
	do 
		scores[$i-2]=${commandLineArray[$i]%.*}  
	done
fi

numberOfScores=$((numberOfArguments - 2))

((sum = ${scores[@]/%/+}0))

average=$((sum / numberOfScores))

if [[ $average -lt 70 ]];then
	echo "Sorry $1 $2, but you will have to retake the class!"
	exit
else 
	echo $@
	echo "Congratulations $1 $2, you passed with an average of $average!"
fi
	




