# Simple Array Utilities in C

A small experimental C project for testing and playing around with array operations.  
The idea is to make arrays safer and easier to use without worrying too much about manual memory allocation, overwriting, or common mistakes in C.

## Features

This project implements **dynamic arrays** for both integers (`intArray`) and characters (`charArray`) with common utilities often found in higher-level languages:

- **Dynamic resizing:** The array grows automatically when you push new elements.
- **Basic operations:**  
  - `push` - add an element at the end  
  - `remove` - remove element at a given index  
  - `insert` - insert at a specific index  
- **Iteration and manipulation helpers:**  
  - `foreach` - apply a function to every element (e.g., convert chars to uppercase)  
  - `map` - create a new array by applying a transformation (e.g., shift letters)  
  - `filter` - extract elements meeting a condition (e.g., vowels only)  
- **Utility functions:**  
  - `sort`  
  - `reverse`  
  - `shuffle`  
- **Safe memory management:** `init` and `deAllocate` functions ensure proper allocation and cleanup.

## Structure

 - ***include/*** // Header files (*intArrayLib.h*, *charArrayLib.h*)
 - ***src/*** // Implementation files (*intArrayLib.c*, *charArrayLib.c*)
 - ***examples/*** // Example usage with *main.c*
 - ***Makefile*** // Build automation


## Build Instructions
*Make sure you have GCC and Make installed. Then, from the project root*

```bash
make
```





### To clean up object files and the executable:


```bash
make clean
```


## Example Usage

```c
#include "../include/intArrayLib.h"
#include "../include/charArrayLib.h"
#include <stdio.h>

int main() {
    // ====================
    // INT ARRAY
    // ====================
    struct intArray myInts = {0};

    if (!initIntArray(&myInts, 3)) {
        printf("Failed to initialize int array\n");
        return 1;
    }

    if (!pushInt(&myInts, 42)) {
        printf("Failed to push value into int array\n");
    }

    if (!removeIntAt(&myInts, 1)) {
        printf("Failed to remove value at index 1\n");
    }

    deAllocateIntArray(&myInts);

    // ====================
    // CHAR ARRAY
    // ====================
    struct charArray myChars = {0};

    if (!initCharArray(&myChars, 5)) {
        printf("Failed to initialize char array\n");
        return 1;
    }

    if (!pushChar(&myChars, 'X')) {
        printf("Failed to push char into array\n");
    }

    if (!foreachCharArray(&myChars, toUppercaseChar)) {
        printf("Failed to apply foreach operation\n");
    }

    deAllocateCharArray(&myChars);

    return 0;
}




