all:
	gcc-13 --version
	nasm --version
	gcc-13 -c main.c -o main.o -fno-stack-protector
	nasm -felf64 vector.asm -o vector.o
	nasm -felf64 heap.asm -o heap.o
	gcc-13 main.o vector.o heap.o -o main -no-pie -fno-stack-protector
	rm *.o
