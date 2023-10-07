/*
 * AUTHOR: ASHWIN ABRAHAM
 */
#ifndef HEAP_H
#define HEAP_H

#include "vector.h"

/*
 * This is a max heap of 64 bit unsigned integers
 * The time complexities of the member functions should all be amortized O(1) (unless otherwise mentioned)
 */
typedef struct heap {
    vector arr; /* The array implementation of a heap is used, and we don't store the size of the heap explicitly, so size of heap = size of array */
} __attribute__((packed)) heap;

/*
 * This function behaves like a constructor, should always be called immediately after declaring the heap
 * It takes as argument a pointer to the heap
 */
void init_h(heap *);

/*
 * This function behaves like a destructor, should always be called immediately when the heap goes out of scope
 * It takes as argument a pointer to the heap
 */
void delete_h(heap *);
/*
 * This function returns the size of the heap
 * It takes as argument a pointer to the heap
 */
uint64_t size_h(const heap *);
/* 
 * This function inserts an element into the heap
 * The first argument is a pointer to the heap and the second argument is the element to be inserted
 * This function can have time complexity O(log n)
 */
void insert_h(heap *, uint64_t);

/* 
 * This function returns the maximum element of the heap
 * It takes as argument a pointer to the heap
 */
uint64_t get_max(const heap *);
/*
 * This function removes the maximum element of the heap and returns it
 * It takes as argument a pointer to the heap
 * This function can have time complexity O(log n)
 */
uint64_t pop_max(heap *);


/* Implementing the functions below is optional */

/*
 * This is the heapify function (converts an array into a max heap)
 * It takes as argument a pointer to the heap
 * This function should have time complexity O(n)
 */
void heapify(vector *);


/*
 * This is the heapsort function (sorts an array by converting it into a max heap and repeatedly popping the max element)
 * It takes as argument a pointer to the heap
 * This function should have time complexity O(log n)
 */
void heapsort(vector *);

#endif
