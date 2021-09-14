for dir in *; do
    if [ -d $dir ] 
    then
        cd ./$dir
        rm *.in
        rm *.out
        cd ..
    fi
done