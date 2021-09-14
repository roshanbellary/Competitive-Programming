#!/bin/bash
#runs an inputted cpp file
#input is taken as the file name ie hello.cpp would be run
#if you type "runc hello"
function runc(){
	x=$1
	lol=$x
        x+=".cpp"
        g++ --std=c++17 $x -o $lol
        echo ""
        ./$lol
        rm ./$lol
}
