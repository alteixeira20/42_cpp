#!/bin/bash

run_test()
{
	local	n=$1
	local	input
	local	output

	echo "────────────────────────────────────"
	echo "Test with $n elements:"
	input=$(shuf -i 1-100000 -n "$n" | tr "\n" " ")
	output=$(./PmergeMe $input)
	echo "$output" | grep "Time"
	echo "$output" | grep "After:" | tr ' ' '\n' | tail -n +2 | sort -n -c \
		&& echo "SORTED OK" || echo "NOT SORTED"
	echo "────────────────────────────────────"
}

run_test 5
run_test 30
run_test 300
run_test 3000
run_test 30000
