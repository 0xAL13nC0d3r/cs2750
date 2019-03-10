#!/bin/bash
#Matt Cassell
#Write a Bash shell script to output various commands introduced in class.

clear
echo "Name of script: $0" 

if [  -z $1 ];then
	echo "Usage <name of file> <name of directory>"
	exit
elif [ ! -f $1 ];then
	echo "Invalid file"
	exit
elif [ ! -d $2 ];then
	echo "Invalid directory, type in entire path..."
	exit
fi

echo 
echo -n "Current date and time: " 
date 

echo 
echo -n "Name of user: "
whoami

echo
echo -n "Name of current working directory: " 
echo "$PWD" | sed 's!.*/!!'

echo
echo -n "Name of UNIX machine: " 
hostname

echo
echo -n "Name of login shell: "
echo $SHELL

echo 
echo -n "Contents of the required file: "
file $0

echo 
echo -n "Number of text line in the file: "
wc -l info.sh | awk '{print $1}'

echo 
echo -n "Listing of the required directory: "
ls

echo 
echo -n "Total number of parameters of the script: "
echo $#

echo
echo "Calender for October 2019: "
cal -m 10

path=$(pwd)
echo
echo -n "Disk usage: "
du -h $path

echo 
echo -n "Current number of users in the system: "
who | wc -l

echo
echo -n "Current time: "
date | awk '{print $4}'

 

