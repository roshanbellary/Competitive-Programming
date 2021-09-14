for dir in *; do
    if [ -d $dir ] 
    then
        cd ./$dir
	    rm *.in
        rm *.out
        if [ -d "Input" ] 
        then
            rm -r "Input"
        fi
        if [ -d "Output" ] 
        then
            rm -r "Output"
        fi
        cd ..
    fi

done
