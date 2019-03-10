#!/bin/bash
#Matt Cassell

clear
if [ -z $1 ];then
	echo "usage <directory name>"
	exit
fi

#DO WE NEED TO CHECK TO SEE IF THIS FILE EXISTS? TAKES A WHILE...
#WOULD BE MUCH EASIER TO ASSUME THEY ARE IN PASSED IN DIRECTORY
#DIRECTORY=$(find / -type d -name $1 2>/dev/null)
#echo $DIRECTORY

CURRENT_PATH=$(pwd)
FILES=$CURRENT_PATH/*

for f in $FILES
do
	if [ -d $f ];then
		if [ ! $(ls -A $f) ];then
			echo $f  | sed 's:.*/::' >> EmptyDir.txt
		fi
	fi	

	echo $f | sed 's:.*/::'
done
 



