#!/bin/bash

for i in minidecaf-tests/examples/step*/*.c
do
    riscv64-unknown-elf-gcc $i -o out/ans.out #compile with gcc
    qemu-riscv64 out/ans.out #run it
    expected=$? #get exit code
    
    java -ea -jar build/libs/minidecaf.jar $i out/ta.S
    riscv64-unknown-elf-gcc out/ta.S -o out/ta.out #compile with YOUR COMPILER or some shell script with YOUR COMPILER
    qemu-riscv64 out/ta.out #run the thing we assembled
    actual=$? #get exit code
    echo -n "$i:    "
    if [ "$expected" -ne "$actual" ]
    then
        echo "FAIL actual=$actual expected=$expected"
    else
        echo "OK"
    fi
    rm -f out a.out asm.S 2>/dev/null
done