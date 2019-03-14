#!/bin/bash
#Matt Cassell

clear
if [ -z $1 ] || [ ! -d $1 ];then
	echo "usage <directory name>"
	exit
fi

echo $1
FILES=$1/*
echo $FILES

for f in $FILES
do
	if [ ! $(ls -A $f) ];then
		echo $f  | sed 's:.*/::' >> EmptyDir.txt
	fi
	
	echo $f | sed 's:.*/::'
done
 



