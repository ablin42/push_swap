#!/bin/bash
#DEBUG MODE: bash -x script.sh
#USAGE: ./script.sh "lowest nb" "highest nb" "maximum nb of moves"
arg=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`
nbmove=`./push_swap $arg | wc -l | tr -d " "`
nbtest='0'

while [ $nbmove -le $3 ]
do
	arg=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`
	nbmove=`./push_swap $arg | wc -l | tr -d " "`
	nbtest=$((nbtest+1))
	#echo $nbtest
done

echo "ARGS=[$arg] / NB OF MOVES=[$nbmove] / NB OF TESTS=[$nbtest]"
