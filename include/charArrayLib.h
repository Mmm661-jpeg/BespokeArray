#ifndef CHARARRAYLIB_H
#define CHARARRAYLIB_H  



struct charArray 
{
   char *data;
   int size;
   int capacity;
};




// ====================
// CHAR ARRAY FUNCTIONS
// ====================

int initCharArray(struct charArray *p, int initialCapacity);
int deAllocateCharArray(struct charArray *p);

int pushChar(struct charArray *p, char value);
int popCharArray(struct charArray *p);
int insertCharAt(struct charArray *p, int index, char value);
int removeCharAt(struct charArray *p, int index);
int clearCharArray(struct charArray *p);

int getCharAt(struct charArray *p, int index, char *outValue);
int containsChar(struct charArray *p, char value);
int countChar(struct charArray *p, int *outValue);

int isFullCharArray(struct charArray *p);
int isEmptyCharArray(struct charArray *p);

int toStringChar(struct charArray *p, struct charArray *outValue);

int lazyFillCharArray(struct charArray *p);
int foreachCharArray(struct charArray *p, void (*elementFunc)(char*));

// map/filter functions would return a new charArray
int mapCharArray(struct charArray *p, char (*mapFunc)(char),struct charArray *outValue);
int filterCharArray(struct charArray *p, int (*filterFunc)(char), struct charArray *outValue);

int sortCharArray(struct charArray *p);
int reverseCharArray(struct charArray *p);
int shuffleCharArray(struct charArray *p);

int printCharArray(struct charArray *p);
int copyCharArray(struct charArray *p,struct charArray *outValue);


#endif  