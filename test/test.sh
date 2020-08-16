make
assert() {
    ans=$1
    echo $2 > case.cpp
    riscv64-unknown-elf-gcc -S case.cpp
    ./main.out case.cpp output.s
    riscv64-unknown-elf-gcc output.s -o run    
    qemu-riscv64 run
    res=$?

    if [ $res = $ans ]; then
        echo "OK!  Result: $res, Ans: $ans"
    else
        echo -e "\033[0;31mNG\033[0;39m"
        echo "FAIL! Result: $res, Ans: $ans"
        exit 1
    fi
}

assert 0 'int main() { return 0; }'
assert 42 'int main() { return 42; }'
assert 10 'int main() { return - -10; }'
assert 10 'int main() { return - - +10;}'
assert 10 'int main() { return ~-11;}'
assert 0 'int main() { return ~-1;}'
assert 0 'int main() { return !10;}'
assert 1 'int main() { return !0;}'
assert 21 'int main() { return 5+20-4; }'
assert 41 'int main() { return  12 + 34 - 5 ; }'
assert 47 'int main() { return 5+6*7; }'
assert 15 'int main() { return 5*(9-6); }'
assert 4 'int main() { return (3+5)/2; }'
assert 10 'int main() { return -10+20; }'

assert 1 'int main() { return 0<1; }'
assert 0 'int main() { return 1<1; }'
assert 0 'int main() { return 2<1; }'
assert 1 'int main() { return 0<=1; }'
assert 1 'int main() { return 1<=1; }'
assert 0 'int main() { return 2<=1; }'

assert 1 'int main() { return 1>0; }'
assert 0 'int main() { return 1>1; }'
assert 0 'int main() { return 1>2; }'
assert 1 'int main() { return 1>=0; }'
assert 1 'int main() { return 1>=1; }'
assert 0 'int main() { return 1>=2; }'

assert 0 'int main() { return 0==1; }'
assert 1 'int main() { return 42==42; }'
assert 1 'int main() { return 0!=1; }'
assert 0 'int main() { return 42!=42; }'

assert 1 'int main() { return 1&&1; }'
assert 0 'int main() { return 0&&0; }'
assert 0 'int main() { return 0&&1; }'
assert 0 'int main() { return 1&&0; }'