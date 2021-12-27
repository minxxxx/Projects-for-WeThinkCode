#!/bin/bash

rm errorsnm 2>&1 > /dev/null
rm errorsot 2>&1 > /dev/null

DIRS=$1
for d in $DIRS
do
	FILES=$d/*
	echo "Files : $FILES"

	echo "in $d" >> errorsnm;
	echo "in $d" >> errorsot;

	for f in $FILES
	do
		echo "Processing file $f"
		TYPE=$(file $f)
		/usr/bin/nm $f > sysresnm
		./ft_nm $f > myresnm

		/usr/bin/otool -t $f > sysresotool
		./ft_otool $f > myresotool

		DIFFNM=$(diff sysresnm myresnm)
		DIFFOT=$(diff sysresotool myresotool)

		if [ "$DIFFNM" != "" ]
		then
			echo "ERROR while processing $f"
			echo "diff:"
			echo "$DIFFNM"
			echo "ERROR while processing $f" >> errorsnm
		fi

		if [ "$DIFFOT" != "" ]
		then
			echo "ERROR while processing $f"
			echo "diff:"
			echo "$DIFFOT"
			echo "ERROR while processing $f" >> errorsot
		fi
	done
	echo "" >> errorsnm
	echo "" >> errorsot
done
