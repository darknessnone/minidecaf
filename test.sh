#!/bin/bash

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


cd $(cd $(dirname ${BASH_SOURCE:-$0}); pwd)

echo $PWD

mkdir -p out

assert "0;" 0
assert "10;" 10