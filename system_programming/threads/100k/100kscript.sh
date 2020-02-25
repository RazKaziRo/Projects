#!/bin/bash
echo "100k Sum Of Dividers..."
for i in {0..30000..1500}
  do 
  	echo
  	echo "Num Of Threads: $i "
  	time ./a.out $1 $i
 done