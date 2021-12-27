#!/bin/bash

rm errors 2>&1 > /dev/null

DIRS=$1
for d in $DIRS
do
	FILES=$d/*
	echo "Files : $FILES"

	echo "in $d" >> errors

	for f in $FILES
	do
		echo "Processing file $f"
		TYPE=$(file $f)
		/usr/bin/nm $f > sysres
		./ft_nm $f > myres
		DIFF=$(diff sysres myres)
		if [ "$DIFF" != "" ]
		then
			echo "ERROR while processing $f"
			echo "diff:"
			echo "$DIFF"
			echo "ERROR while processing $f" >> errors
		fi
	done
	echo "" >> errors
done
