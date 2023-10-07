/*
 * AUTHOR: ASHWIN ABRAHAM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "vector.h"
#include "heap.h"

void print_usage(int argc, char **argv)
{
    printf("USAGE: %s <mode>\n", argv[0]);
    puts("<mode> can be c (test compulsary part) or o (test optional part)");
    exit(-1);
}

void print_instructions(char c)
{
    if(c == 'c')
    {
        puts("Enter input as <mode> <num>");
        puts("<mode> can be i (insert), d (delete), m (get max)");
        puts("<num> is required only for mode i, and represents the number to be inserted");
    }
    else if(c == 'o')
    {
        puts("Enter all the elements of the array (non-negative integers)");
    }
    else exit(-1);
}

int main(int argc, char **argv)
{
    if(argc != 2) print_usage(argc, argv);
    if(strcmp(argv[1], "c") == 0)
    {
        print_instructions('c');
        heap h;
        init_h(&h);
        char c[2];
        while(scanf("%1s", c) == 1)
        {
            if(strcmp(c, "i") == 0)
            {
                uint64_t num;
                if(scanf("%llu", &num) == 1)
                {
                    insert_h(&h, num);
                }
                else
                {
                    delete_h(&h);
                    print_instructions('c');
                    exit(-1);
                }
            }
            else if(strcmp(c, "d") == 0)
            {
                if(size_h(&h) > 0)
                {
                    uint64_t num = pop_max(&h);
                    printf("Popped element: %llu\n", num);
                }
                else puts("Heap is empty");
            }
            else if(strcmp(c, "m") == 0)
            {
                if(size_h(&h) > 0)
                {
                    uint64_t num = get_max(&h);
                    printf("Max element: %llu\n", num);
                }
                else puts("Heap is empty");
            }
            else
            {
                delete_h(&h);
                print_instructions('c');
                exit(-1);
            }
        }
        delete_h(&h);
    }
    else if(strcmp(argv[1], "o") == 0)
    {
        print_instructions('o');
        vector v;
        init_v(&v);
        uint64_t num;
        while(scanf("%llu", &num) == 1)
        {
            push_v(&v, num);
        }
        heapsort(&v);
        printf("The sorted array is: ");
        for(uint64_t i = 0; i < size_v(&v); ++i)
        {
            printf("%llu ", *get_element_v(&v, i));
        }
        puts("");
        delete_v(&v);
    }
    else print_usage(argc, argv);
}