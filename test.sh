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

assert 0 0
assert 10 10
assert 1+3 4
assert 1+3+8 12
assert ' 1 + 2 + 8  ' 11
assert 2-3 255
assert 1-5+1 253
assert 1*3+4 7
assert 3+2*4-1 10
assert 4/2+2*4/1 10
assert 1+2*3*4 25
assert "3*(2+4)" 18
assert "1+((2)+4/2)" 5
assert "(3+4*2)+3*(1+2)-4" 16
assert "-3" 253
assert "-3+5" 2
assert "100+-3*-3" 109
assert "-2*+8" 240
assert "-3" 253
assert "-3+5" 2
assert "100+-3*-3" 109
assert "-2*+8" 240
assert "4==4" 1
assert "4==2" 0
assert "4!=4" 0
assert "4!=2" 1
assert "4<5" 1
assert "4<4" 0
assert "4<=4" 1
assert "4<3" 0
assert "4>4" 0
assert "4>3" 1
assert "4>=5" 0
assert "4>=4" 1
assert "4+ 4*2 >=15+3*(-2)" 1
