#!/bin/bash
#Matthew Cassell
#Transform contact_one.sh(sec 5.2)

clear

while true
do
	echo "Enter a name to search (type q to quit): "
	read name
	
	if  [ $name == "q" ];then
		exit
	fi
	
	nameCheck=$(grep -i $name myContactList)
	
	if [[ -z $nameCheck ]];then
		echo "$name is NOT in the list!"	
	else 
		echo "$nameCheck is in the list!"
	fi
done


	 
