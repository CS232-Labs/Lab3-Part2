# Question 3

In this assignment you will implement a $\textbf{max heap}$ in the $\texttt{x86-64}$ assembly language. To do this, you will also have to implement a $\textbf{dynamic array}$ (ie a $\textbf{vector}$) in assembly. Note that a viva may be conducted for this lab.

## Installation Instructions

This lab assumes you are using a 64 bit Linux OS on an $\texttt{x86}$ series CPU. 

Mac Users must use Docker.

You will need $\texttt{gcc-13}$ and NASM for this lab.

To install $\texttt{gcc-13}$:

```
sudo apt-get install -y software-properties-common
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install -y gcc-13
```

To install NASM:

```
wget http://archive.ubuntu.com/ubuntu/pool/universe/n/nasm/nasm_2.15.05-1_amd64.deb
sudo dpkg -i nasm_2.15.05-1_amd64.deb
```

## General Instructions

Your task will be to implement the member functions of the max heap and vector in assembly. The rest of the code is in C, including the main function. The commands to compile the assembly code along with the C code is already present in the Makefile, you just have to run $\texttt{make}$ to compile the executable.

You will implement the functions in the files $\texttt{vector.asm}$ and $\texttt{heap.asm}$. The function declarations along with descriptive comments explaining how they are to be implemented can be found in $\texttt{vector.h}$ and $\texttt{heap.h}$. Follow all the instructions given in these files.

The main function is present in $\texttt{main.c}$. It takes one command line argument which can be either $\texttt{c}$ or $\texttt{o}$. $\texttt{c}$ is used for checking the compulsory test cases and $\texttt{o}$ is used to check the optional test cases. In both cases, the program will ask you to enter queries.

In the compulsory mode, 3 kinds of queries are distinguished - insert, delete, and max. Insert queries are of the form $\texttt{i <num>}$ and insert the number into the heap. Delete queries are of the form $\texttt{d}$ and pop the maximum element from the heap and print it out on the terminal. Max queries are of the form $\texttt{m}$ and print out the maximum element of the heap.

A sample run of the program in compulsory mode is:

```$ ./main c```

```Enter input as <mode> <num>```

```<mode> can be i (insert), d (delete), m (get max)```

```<num> is required only for mode i, and represents the number to be inserted```

```i 3```

```i 2```

```m```

```Max element: 3```

```i 7```

```m```

```Max element: 7```

```d```

```Popped element: 7```

```m```

```Max element: 3```

In optional mode, the program will ask you to enter a sequence of non-negative integers, and will sort them (using heapsort) and display the sorted output.

A sample run of the program in optional mode is:

```$ ./main o```

```Enter all the elements of the array (non-negative integers)```

```8 3 2 2 3 4 5```

```The sorted array is: 2 2 3 3 4 5 8```

## Assembly Programming

Some resources for coding in $\texttt{x86-64}$ assembly are:


* [Registers & Memory in x86](https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture)
* [System calls for Linux in x86](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
* [NASM Tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
* [x86 Instruction cheatsheet](https://www.felixcloutier.com/x86/)
* [YouTube Tutorial 1](https://www.youtube.com/watch?v=tzkwW2SXWmQ)
* [YouTube Tutorial 2](https://www.youtube.com/watch?v=9sumRfIgaHs)
* [YouTube Tutorial 3](https://www.youtube.com/watch?v=9if9kS92Ha8)
## Dealing with structs in assembly

In assembly, there are no variables per se and there are no datatypes, so we cannot access members of a struct directly by using the $\texttt{.}$ or $\texttt{->}$ operators. To access members of structs, we must first learn how structs are stored in memory.

Take a look at the struct $\texttt{vector}$ whose members are:

* ```uint64_t buff_size```
* ```uint64_t size```
* ```uint64_t *ptr```

declared in that order. The members of the struct are stored contiguously in memory.

So if I have a ```vector``` at adress $\texttt{0x10}$, then ```buff_size``` is stored in the 8 bytes starting at $\texttt{0x10}$, ```size``` is stored in the 8 bytes starting at $\texttt{0x18}$ and ```ptr``` is stored in the 8 bytes starting at $\texttt{0x20}$ (there is also something known as [struct padding](https://www.scaler.com/topics/structure-padding-in-c/), but you don't need to worry about that, as that has been disabled for this lab).

So if you have the address of a ```vector``` stored in $\texttt{rax}$, then you can get it's ```buff_size``` member by accessing $\texttt{[rax]}$, ```size``` by accessing $\texttt{[rax + 8]}$ and ```ptr``` by accessing $\texttt{[rax + 16]}$.

## Some tips for programming in assembly

A good way to program in assembly is to first think how control structures such as if-else statements, for loops and while loops could be implemented in assembly. Then, code the entire program in C, and convert it line-by-line into the corresponding assembly code. Make heavy use of comments in order to know which line of code we are at, which register is storing what variable, etc.

PS: Do not think of compiling your C code and copying the resulting assembly code - handwritten assembly is very different from compiler-generated assembly, and the two can be distinguished very easily.

## Submission Instructions

You must submit only $\texttt{vector.asm}$ and $\texttt{heap.asm}$ inside the file ```roll_number.tar.gz``` or ```roll_number.zip```.
