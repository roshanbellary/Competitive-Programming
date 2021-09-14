for dir in *; do
    if [ -d $dir ] 
    then
        cd ./$dir
        if [ -d "c++" ]
        then
            echo c++
            mv ./c++/* .
            rm -r c++
        fi
        if [ -d "java" ]
        then
            echo java
            mv ./java/* .
            rm -r java
        fi
        cd ..
    fi
done
