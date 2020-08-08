java -jar build/libs/minidecaf.jar out/tmp.mdf out/tmp.S
riscv64-unknown-elf-gcc out/tmp.S -o out/tmp.out
qemu-riscv64 out/tmp.out
echo $?