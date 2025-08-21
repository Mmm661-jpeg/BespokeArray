#include "../include/intArrayLib.h"
#include <stdio.h> 
#include <time.h>
#include <stdlib.h> 
#include <limits.h>

static int randomInit = 0;

static void initRandom()
{
    if(!randomInit)
    {
        srand((unsigned)time(NULL));
        randomInit = 1;
    }
}

static void swapInt(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;


}

static int compareInts(const void *a, const void *b)
{
    int intA = *(int*)a;
    int intB = *(int*)b;
    if(intA < intB)
    {
        return -1;
    }
    else if (intA > intB)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

static void swapChar(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


// ====================
// INT ARRAY FUNCTIONS
// ====================

int initIntArray(struct intArray *p, int initialCapacity)
{
    if (p == NULL || initialCapacity < 1) {
        return 0;
    }

    if (p->data != NULL) {
        free(p->data);
    }

    int *mallocPointer = malloc(initialCapacity * sizeof(int));
    if (mallocPointer == NULL) {
        p->data = NULL;
        p->size = 0;
        p->capacity = 0;
        return 0;
    }

    p->data = mallocPointer;
    p->size = 0;
    p->capacity = initialCapacity;

    return 1;
}

int deAllocateIntArray(struct intArray *p)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    free(p->data);   
    p->data = NULL;
    p->size = 0;
    p->capacity = 0;

    return 1;
}


int pushInt(struct intArray *p, int value)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    if(p->size < p->capacity)
    {
        p ->data[p->size] = value;

        p->size++;

       
    }
    else
    {
        int *newArr = realloc(p->data,(p->size+2) * sizeof(int));
        if(newArr == NULL)
        {
            return 0;
        }

        p->data = newArr;

        p->data[p->size] = value;
        p->capacity = p->size+2;
        p->size++;
       
    }

    return 1;

   
}

int popIntArray(struct intArray *p)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    if(p->size == 0)
    {
        return 0;
    }

    p->size--;
    p->data[p->size] = 0;

    return 1;

}

int insertIntAt(struct intArray *p, int index, int value) //shift values around instead.
{
    if(p == NULL || p->data == NULL || index < 0 || index >= p->size)
    {
        return 0;
    }

    if(p->size >= p->capacity)
    {
        int *newArr = realloc(p->data, (p->capacity + 2) * sizeof(int));

        if(newArr == NULL)
        {
            return 0;
        }
           

        p->data = newArr;
        p->capacity += 2;
    }


    for(int i = p->size; i > index;i--)
    {
        p->data[i] = p->data[i-1];
    }
    
    p->data[index] = value;
    p->size++;

    return 1;

   
}


int removeIntAt(struct intArray *p, int index)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    if(index >=p->size || index < 0)
    {
        return 0;
    }

    for(int i = index;i <p->size -1 ;i++)
    {
        p->data[i] = p->data[i+1];
    }

     p->size--;

     return 1;
}


int clearIntArray(struct intArray *p)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    for (int i = 0;i<p->size;i++)
    {
        p->data[i] = 0;
    }

    p->size = 0;

    return 1;


}


int getIntAt(struct intArray *p, int index,int *outValue)
{
    if(p == NULL || p->data == NULL  || outValue == NULL)
    {
        return 0;
    }


    if(index < 0 || index >= p->size)
    {
        return 0;
    }

    int getIntResult = p->data[index];

    *outValue = getIntResult;

    return 1;
}


int containsInt(struct intArray *p, int value)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    for(int i=0;i<p->size;i++)
    {
        int arrayValue = p->data[i];

        if(arrayValue == value)
        {
            return 1;
        }
    }

    return 0;

}

int countInt(struct intArray *p, int value, int *outValue) //count how many times given value appears
{
    if(p == NULL || p->data == NULL  || outValue == NULL)
    {
        return 0;
    }

    int counter = 0;

    for(int i=0;i < p->size;i++)
    {
        if(value == p->data[i])
        {
            counter++;
        }
    }

    *outValue = counter;

    return 1;

}

int isFullIntArray(struct intArray *p, int *outValue)
{
    if(p == NULL || p->data == NULL || outValue == NULL)
    {
        return 0;
    }

    if(p->size >= p->capacity)
    {
        *outValue = 1;
    }
    else
    {
        *outValue = 0;
    }

    return 1;

}


int isEmptyIntArray(struct intArray *p, int *outValue)
{
    if(p == NULL || p->data == NULL || outValue == NULL)
    {
        return 0;
    }

    if(p->size == 0)
    {
        *outValue = 1;
    }
    else
    {
        *outValue = 0;
    }

    return 1;

}


int sumInt(struct intArray *p, int *outValue)
{
    if(p == NULL || p->data == NULL || outValue == NULL)
    {
        return 0;
    }

    int summary = 0;

    for(int i = 0;i < p->size;i++)
    {
        summary += p->data[i];
    }

    *outValue = summary;

    return 1;
}


int averageIntArray(struct intArray *p, int *outValue)
{
    if(p == NULL || p->data == NULL || outValue == NULL || p->size == 0)
    {
        return 0;
    }

    int summary = 0;

    for(int i = 0;i < p->size;i++)
    {
        summary += p->data[i];
    }

    int avrage = summary / p->size;

    *outValue = avrage;
    return 1;


}

int medianIntArray(struct intArray *p, int *outValue)
{
    if(p == NULL || p->data == NULL || outValue == NULL || p->size == 0)
    {
        return 0;
    }

    int *tempArray = malloc(p->size * sizeof(int));

    if(tempArray == NULL)
    {
        return 0;
    }

    for(int i = 0;i < p->size;i++)
    {
       tempArray[i] = p->data[i];
    }

    qsort(tempArray,p->size,sizeof(int),compareInts);


    if(p->size % 2 == 1)
    {
        *outValue = tempArray[p->size / 2];
    }
    else
    {
        *outValue = (tempArray[p->size / 2 - 1] + tempArray[p->size / 2]) / 2;
    }

    free(tempArray);

    return 1;

}

int getMaxIntArray(struct intArray *p, int *outValue)
{
    if(p == NULL || p->data == NULL || outValue == NULL || p->size == 0)
    {
        return 0;
    }

    int currentMax = p->data[0];

    for (int i = 0;i < p->size;i++)
    {
        if(p->data[i]>currentMax)
        {
            currentMax = p->data[i];
        }
    }

    *outValue = currentMax;
    return 1;
}
int getMinIntArray(struct intArray *p, int *outValue)
{
    if(p == NULL || p->data == NULL || outValue == NULL || p->size == 0)
    {
        return 0;
    }

    int currentMin = p->data[0];

    for(int i=0;i < p->size;i++)
    {
        if(p->data[i] < currentMin)
        {
            currentMin = p->data[i];
        }
    }

    *outValue = currentMin;
    return 1;
}


int productOfIntArray(struct intArray *p, int *outValue)
{
    if(p == NULL || p->data == NULL || outValue == NULL || p->size == 0)
    {
        return 0;
    }

    int product = 1;
   

    for(int i =0;i < p->size;i++)
    {
        if(p->data[i] != 0 && ((product > INT_MAX / p->data[i]) || (product < INT_MIN /  p->data[i])))
        {
            return 0;
        }

       product *= p->data[i];
      
    }

    *outValue = product;
    return 1;
}



int lazyFillIntArray(struct intArray *p)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    initRandom();

    //get random number withing range,check what spots to fill,fill

    for(int i = p->size;i < p->capacity;i++)
    {
        p->data[i] = rand() % 100;
        p->size++;
    }

    return 1;


}

int foreachIntArray(struct intArray *p, void (*elementFunc)(int*))
{
    if(p == NULL || p->data == NULL || !elementFunc)
    {
        return 0;
    }

    for(int i = 0;i < p->size;i++)
    {
        int *arayAdress = &p->data[i];

        elementFunc(arayAdress);
    }

    return 1;
    
}

// map/filter functions would return a new intArray
int mapIntArray(struct intArray *p,struct intArray *outArray ,int (*mapFunc)(int))
{
    if(p == NULL || p->data == NULL || !mapFunc)
    {
       return 0;
    }

    if(outArray->data !=NULL)
    {
        free(outArray->data);
        outArray->data = NULL;
        outArray->capacity = 0;
        outArray->size=0;
    }

    
    int *newArrP = malloc(p->size * sizeof(int));

    if(newArrP == NULL)
    {
        return 0;
    }


    for(int i = 0;i < p->size;i++)
    {
        newArrP[i] = mapFunc(p->data[i]);
    }

    outArray ->data = newArrP;
    outArray->size = p->size;
    outArray ->capacity = p ->size;


   

    return 1;
    

}



int filterIntArray(struct intArray *p,struct intArray *outArray,int (*filterFunc)(int))
{
    if(p == NULL || p->data == NULL || !filterFunc)
    {
       return 0;
    }

    if (outArray->data != NULL)
    {
        free(outArray->data);
        outArray->data = NULL;
        outArray->size = 0;
        outArray->capacity = 0;
    }

    int counter = 0;

    for(int i = 0;i < p->size;i++)
    {
        if(filterFunc(p->data[i]))
        {
            counter++;
        }
    }

    if(counter == 0)
    {
        return 0;
    }

    int *newArrPointer = malloc(counter * sizeof(int));

    if(newArrPointer == NULL)
    {
        return 0;
    }



    outArray->data = newArrPointer;

    int secondCounter = 0;

    for(int i = 0;i < p->size;i++)
    {
        if(filterFunc(p->data[i]))
        {
           outArray->data[secondCounter] = p->data[i];
           secondCounter++;
        }

       
    }

    outArray->size = secondCounter;
    outArray->capacity = counter;

    return 1;
}

int sortIntArray(struct intArray *p)
{
    if(p == NULL|| p->data == NULL)
    {
        return 0;
    }


  

    for(int i =0;i < p->size-1;i++)
    {
        int swapped = 0;

        for(int j =0;j < p->size -i -1;j++)
        {
            if(p->data[j] > p->data[j+1])
            {
                swapInt(&p->data[j],&p->data[j+1]);
                swapped = 1;
            }
        }

        if(!swapped)
        {
            break;
        }
    }

    return 1;
}

int reverseIntArray(struct intArray *p)
{
    if(p == NULL|| p->data == NULL)
    {
        return 0;
    }

    for(int i = 0; i < p->size / 2; i++)
    {
        int indexToSwap = p->size -1 - i;
        swapInt(&p->data[i],&p->data[indexToSwap]);
    }

    return 1;
}

int shuffleIntArray(struct intArray *p)
{
    if(p == NULL|| p->data == NULL)
    {
        return 0;
    }

    initRandom();

    for(int i=0;i<p->size-1;i++)
    {
        int randomIndex = i + rand() % (p->size - i);

        swapInt(&p->data[i],&p->data[randomIndex]);
    }

    return 1;
}

int printIntArray(struct intArray *p)
{
    if(p == NULL|| p->data == NULL)
    {
        return 0;
    }

    for(int i = 0;i < p->size;i++)
    {
        printf("%d",p->data[i]);

       if (i < p->size - 1)  
        {
            printf(",");
        }
    }

    printf("\n");

    return 1;
}

int copyIntArray(struct intArray *p, struct intArray *outValue)
{
    if(p == NULL|| p->data == NULL || outValue == NULL || p->capacity <1)
    {
        return 0;
    }

    if (outValue->data == NULL || outValue->capacity < p->capacity)
    {

        int *newData = malloc(p->capacity * sizeof(int));
        if(newData == NULL)
        {
            return 0;
        }


        if(outValue->data != NULL)
        {
            free(outValue->data);
        }

        outValue->data = newData;
        outValue->capacity = p->capacity;
    }

    for (int i = 0; i < p->size; i++)
    {
        outValue->data[i] = p->data[i];
    }

    outValue->size = p->size;

    return 1;

  

  
}


