#! /bin/bash
#99dan.sh

for((i=2; i<9; i++))
	do
	for((j=1; j<9; j++))
		do
		((num=i*j))
		echo "$i X $j = $num"
		done
done

