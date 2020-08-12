for i in test/step10/*.c
do
    gcc $i             #compile with gcc
    ./a.out                 	#run it
    expected=$?             	#get exit code
    ./chibicc $i > chibi.s      #compile with YOUR COMPILER or some shell script with YOUR COMPILER
    gcc -static chibi.s -o chibi.out
    base="${i%.*}"
    ./chibi.out                #run the thing we assembled
    actual=$?                  #get exit code
    echo -n "$i:    "
    if [ "$expected" -ne "$actual" ]
    then
        echo "FAIL" 
        echo $actual
    else
        echo "OK"
    fi
    rm chibi.out a.out
done

#tested in ubutnu 20.04 x86-64
