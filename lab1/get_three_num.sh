#! /bin/bash

echo "first num"
read n
max=$n
min=$n

i=2
while [ $i -le 3 ]
do
	echo $i" input"
	read n

	if [ $n -ge $max ]; then
		max=$n
	fi
	if [ $n -le $min ]; then
		min=$n
	fi
	i=`expr $i + 1`
done
echo "max : $max, min : $min"
exit 0
