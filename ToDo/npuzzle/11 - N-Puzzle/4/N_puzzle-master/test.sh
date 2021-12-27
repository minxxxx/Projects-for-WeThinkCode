#!/bin/bash
YEP=0
for i in {1..1000}
do
	echo $i
	RES=`./npuzzle --manhattan --random 3 | grep solvable`
	if [ "$RES" == "" ]
	then
		YEP=$((YEP + 1))
	fi
done
echo "result: "$YEP
