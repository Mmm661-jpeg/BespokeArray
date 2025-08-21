#ifndef INTARRAYLIB_H
#define INTARRAYLIB_H  


struct intArray 
{
   int *data;
   int size;
   int capacity;
};


// ====================
// INT ARRAY FUNCTIONS
// ====================

int initIntArray(struct intArray *p, int initialCapacity);
int deAllocateIntArray(struct intArray *p);

int pushInt(struct intArray *p, int value);
int popIntArray(struct intArray *p);
int insertIntAt(struct intArray *p, int index, int value);
int removeIntAt(struct intArray *p, int index);
int clearIntArray(struct intArray *p);

int getIntAt(struct intArray *p, int index, int *outValue);
int containsInt(struct intArray *p, int value);
int countInt(struct intArray *p, int value,  int *outValue);

int isFullIntArray(struct intArray *p, int *outValue);
int isEmptyIntArray(struct intArray *p, int *outValue);

int sumInt(struct intArray *p, int *outValue);
int averageIntArray(struct intArray *p, int *outValue);
int medianIntArray(struct intArray *p, int *outValue);
int getMaxIntArray(struct intArray *p, int *outValue);
int getMinIntArray(struct intArray *p, int *outValue);
int productOfIntArray(struct intArray *p, int *outValue);

int lazyFillIntArray(struct intArray *p);
int foreachIntArray(struct intArray *p, void (*elementFunc)(int*));


int mapIntArray(struct intArray *p,struct intArray *outArray ,int (*mapFunc)(int));
int filterIntArray(struct intArray *p,struct intArray *outArray ,int (*filterFunc)(int));

int sortIntArray(struct intArray *p);
int reverseIntArray(struct intArray *p);
int shuffleIntArray(struct intArray *p);

int printIntArray(struct intArray *p);
int copyIntArray(struct intArray *p, struct intArray *outValue);


#endif