all:
	gcc-13 --version
	nasm --version
	gcc-13 -c -O3 main.c -o main.o
	nasm -felf64 vector.asm -o vector.o
	nasm -felf64 heap.asm -o heap.o
	gcc-13 -flto main.o vector.o heap.o -o main -no-pie
	rm *.o
