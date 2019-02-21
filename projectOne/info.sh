#!/bin/bash

path = $(pwd)

clear
echo "Name of script: $0" 

if [  -z $1 ];then
	echo
	echo "Usage <name of file> <name of directory>"
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
pwd

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
wc -l info.sh

echo 
echo -n "Listing of the required directory: "
ls

echo 
echo -n "Total number of parameters of the script: "
echo $#

echo
echo "Calender for October 2019: "
cal -m 10

echo
echo -n "Disk usage: "
du -h $path

echo 
echo -n "Current number of users in the system: "
who | wc -l


echo
echo -n "Current time: "
date | awk '{print $4}'

 

