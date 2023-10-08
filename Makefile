all:
	$(CC) --version
	nasm --version
	$(CC) -c -O3 main.c -o main.o
	nasm -felf64 vector.asm -o vector.o
	nasm -felf64 heap.asm -o heap.o
	$(CC) -flto main.o vector.o heap.o -o main -no-pie
	rm *.o
