#! /bin/bash
i=5
j=1
while [ $i -gt 0 ]
do
	while [ $j -le $i ]
	do
		echo -n "*"
		j=`expr $j + 1`
	done
	j=1
	i=`expr $i - 1`
	echo ""
done
