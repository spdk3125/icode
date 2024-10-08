#!/bin/bash

# Declare an array
array=(64 34 25 5 22 11 90 12)

# Get the length of the array
n=${#array[@]}

# Selection sort algorithm
for ((i=0; i<n-1; i++)); do
	minid=$i
	for ((j=i+1; j<n; j++)); do
		if((array[j] < array[minid])); then
			minid=$j
		fi
	done
	minval=${array[minid]}
	for((k=minid; k<i; k--));do
		array[k]=${array[k-1]}
	done
	array[i]=$minval;
done

echo  "array= ${array[@]}"


