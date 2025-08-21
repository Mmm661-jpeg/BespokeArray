#include "../include/intArrayLib.h"
#include "../include/charArrayLib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

// foreach helper
void toUppercaseChar(char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c = *c - 'a' + 'A';
    }
}

// filter helper
int isVowel(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

// map helper
char shiftChar(char c) {
    return c + 1;
}

int main()
{
    // ====================
    // INT ARRAY EXAMPLES
    // ====================
    struct intArray testing = {0};

    if(!initIntArray(&testing, 3)) {
        printf("Failed to initialize int array\n");
        return 1;
    }

    if(!lazyFillIntArray(&testing)) {
        printf("Failed to lazy fill int array\n");
        deAllocateIntArray(&testing);
        return 1;
    }

    printf("IntArray contents:\n");
    if(!printIntArray(&testing)) {
        printf("Failed to print int array\n");
        deAllocateIntArray(&testing);
        return 1;
    }

    if(!pushInt(&testing, 42)) {
        printf("Failed to push value into int array\n");
    }
    printf("After pushing 42:\n");
    printIntArray(&testing);

    if(!removeIntAt(&testing, 1)) {
        printf("Failed to remove value at index 1\n");
    }
    printf("After removing index 1:\n");
    printIntArray(&testing);

    deAllocateIntArray(&testing);


    // ====================
    // CHAR ARRAY EXAMPLES
    // ====================
    struct charArray chars = {0};

    if(!initCharArray(&chars, 5)) {
        printf("Failed to initialize char array\n");
        return 1;
    }

    if(!lazyFillCharArray(&chars)) {
        printf("Failed to lazy fill char array\n");
        deAllocateCharArray(&chars);
        return 1;
    }
    printf("\nRandom CharArray:\n");
    printCharArray(&chars);

    if(!pushChar(&chars, 'X') || !pushChar(&chars, 'y')) {
        printf("Failed to push values into char array\n");
    }
    printf("After pushing X and y:\n");
    printCharArray(&chars);

    if(!insertCharAt(&chars, 2, 'Z')) {
        printf("Failed to insert at index 2\n");
    }
    printf("After inserting Z at index 2:\n");
    printCharArray(&chars);

    if(!sortCharArray(&chars)) {
        printf("Failed to sort char array\n");
    }
    printf("After sorting:\n");
    printCharArray(&chars);

    if(!reverseCharArray(&chars)) {
        printf("Failed to reverse char array\n");
    }
    printf("After reversing:\n");
    printCharArray(&chars);

    if(!shuffleCharArray(&chars)) {
        printf("Failed to shuffle char array\n");
    }
    printf("After shuffling:\n");
    printCharArray(&chars);

    if(!foreachCharArray(&chars, toUppercaseChar)) {
        printf("Failed to foreach uppercase\n");
    }
    printf("After foreach (toUppercase):\n");
    printCharArray(&chars);

    struct charArray mapped = {0};
    if(!initCharArray(&mapped, 1) || !mapCharArray(&chars, shiftChar, &mapped)) {
        printf("Failed to map char array\n");
    } else {
        printf("Mapped (shift +1):\n");
        printCharArray(&mapped);
    }

    struct charArray filtered = {0};
    if(!initCharArray(&filtered, 1) || !filterCharArray(&chars, isVowel, &filtered)) {
        printf("Failed to filter char array (maybe no vowels)\n");
    } else {
        printf("Filtered (only vowels):\n");
        printCharArray(&filtered);
    }

    deAllocateCharArray(&chars);
    deAllocateCharArray(&mapped);
    deAllocateCharArray(&filtered);

    return 0;
}
