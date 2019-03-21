#!/bin/bash
#Matt Cassell
#Write a script that will loop through a directory and display file names. If a directory is empty add it to a text file.

clear
if [ -z $1 ] || [ ! -d $1 ];then
	echo "usage <directory name>"
	exit
fi

FILES=$1/*

for f in $FILES
do
	if [ ! $(ls -A $f) ];then
		echo $f  | sed 's:.*/::' >> EmptyDir.txt
	fi
	
	echo $f | sed 's:.*/::'
done
 



