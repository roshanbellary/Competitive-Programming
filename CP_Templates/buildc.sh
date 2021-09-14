#!/bin/bash
#takes as input in command line the file name without the extension
# ie on terminal to build hello.cpp you would run "buildc hello"
function buildc(){
	x=$1
	lol=$x
	x+=".cpp"
	g++ --std=c++17 $x -o $lol
	echo ""
	./$lol
}
