#!/bin/bash

for i in examples/*/*.c
do
    riscv64-unknown-elf-gcc $i             #compile with gcc
    qemu-riscv64 ./a.out                 	#run it
    expected=$?             	#get exit code
    /media/chyyuu/ca8c7ba6-51b7-41fc-8430-e29e31e5328f/thecode/rust/compilers/minidecaf/target/debug/minidecaf $i  >> asm.S 
    riscv64-unknown-elf-gcc asm.S -o out   #compile with YOUR COMPILER or some shell script with YOUR COMPILER
    base="${i%.*}"
    qemu-riscv64 ./out                      #run the thing we assembled
    actual=$?                  #get exit code
    echo -n "$i:    "
    if [ "$expected" -ne "$actual" ]
    then
        echo "FAIL"
    else
        echo "OK"
    fi
    rm -f out a.out asm.S 2>/dev/null
done

assert() {
    echo $1 > out/tmp.mdf
    java -jar build/libs/minidecaf.jar out/tmp.mdf out/tmp.S

    riscv64-unknown-elf-gcc out/tmp.S -o out/tmp.out
    qemu-riscv64 out/tmp.out

    res=$?

    if [ $res == $2 ]; then
        echo "OK"
    else
        echo -e "\033[0;31mNG\033[0;39m"
        echo "Result: $res, Ans: $ans"
    fi
}