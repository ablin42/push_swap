#!/bin/bash
#DEBUG MODE: bash -x script.sh
#USAGE: ./script.sh "lowest nb" "highest nb" "maximum nb of moves"
arg=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`
nbmove=`./push_swap $arg | wc -l | tr -d " "`
nbtest='0'
moyenne='0'
limit=$(($2 * 100))

while [[ $nbmove -le $3  &&  $nbtest -le $limit ]]
do
	arg=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`
	echo "prout"
	nbmove=`./push_swap $arg | wc -l | tr -d " "`
	echo "XD"
	nbtest=$((nbtest+1))
	moyenne=$((moyenne + nbmove))
	echo $nbtest
done

moyenne=$((moyenne / nbtest))

echo "ARGS=[$arg]"
echo "NB OF MOVES=[$nbmove]"
echo "NB OF TESTS=[$nbtest]"
echo "MOYENNE=[$moyenne]"
