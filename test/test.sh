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
