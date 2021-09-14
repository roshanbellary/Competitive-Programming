for dir in *; do
    if [ -d $dir ] 
    then
        cd ./$dir
        rm -rf .git
        cd ..
    fi
done