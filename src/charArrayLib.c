#include "../include/charArrayLib.h"
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

static void swapChar(char *a,char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;


}


static int compareChar(const void *a, const void *b) //Compare the acsii indexes. qsort.
{
    char charA = *(const char*)a;
    char charB = *(const char*)b;
    if(charA < charB)
    {
        return -1;
    }
    else if (charA > charB)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}





int initCharArray(struct charArray *p, int initialCapacity)
{
    if(p == NULL || initialCapacity < 1)
    {
        return 0;
    }

    if(p->data != NULL)
    {
        free(p->data);
        p->data = NULL;
        p->capacity = 0;
        p->size = 0;
    }

    char *charPointer = malloc(initialCapacity * sizeof(char));

    if(charPointer == NULL)
    {
        return 0;
    }

    p->data = charPointer;
    p->capacity = initialCapacity;
    p->size = 0;

    return 1;
}

int deAllocateCharArray(struct charArray *p)
{
    if(p == NULL)
    {
        return 0;
    }

    free(p->data);
    p->data = NULL;
    p->capacity = 0;
    p->size = 0;

    return 1;
}

int pushChar(struct charArray *p, char value)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    if(p->size>=p->capacity)
    {
        char *charPointer = realloc(p->data,(p->capacity +2) * sizeof(char));

        if(charPointer == NULL)
        {
            return 0;
        }

        p->data = charPointer;
        p->capacity = p->capacity +2;

    }

    p->data[p->size] = value;
    p->size++;

    return 1;
}

int popCharArray(struct charArray *p)
{
    if(p== NULL || p->data == NULL || p->size == 0)
    {
        return 0;
    }

    p->size--;

    return 1;
   
}

int insertCharAt(struct charArray *p, int index, char value)
{
    if(p== NULL || p->data == NULL || index < 0)
    {
        return 0;
    }

    if(p->size >=p->capacity)
    {
        char *charPointer = realloc(p->data,(p->capacity +2) * sizeof(char));

        if(charPointer == NULL)
        {
            return 0;
        }

        p->data = charPointer;
        p->capacity +=2;
    }

    for(int i = p->size;i > index;i--)
    {
        p->data[i] = p->data[i-1];
    }

    p->data[index] = value;
    p->size++;

    return 1;
}

int removeCharAt(struct charArray *p, int index)
{
    if(p== NULL || p->data == NULL || index < 0 || index >=p->size)
    {
        return 0;
    }

    for(int i = index;i < p->size-1;i++)
    {
        p->data[i] = p->data[i+1];
    }

    p->size--;
    return 1;


}

int clearCharArray(struct charArray *p)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    for (int i = 0;i < p->size;i++)
    {
        p->data[i] = '\0'; 
    }

    p->size = 0;

    return 1;
}

int getCharAt(struct charArray *p, int index, char *outValue)
{
    if(p== NULL || p->data == NULL || index < 0 || index >=p->size)
    {
        return 0;
    }

    char result = p->data[index];

    *outValue = result;

    return 1;


}


int containsChar(struct charArray *p, char value)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    for(int i=0;i < p->size;i++)
    {
        if(p->data[i] == value)
        {
            return 1;
        }
    }

    return 0;
}


int countChar(struct charArray *p, int *outValue)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    *outValue = p->size;

    return 1;
}

int isFullCharArray(struct charArray *p)
{
    if(p== NULL || p->data == NULL)
    {
        return 0;
    }

    if(p->size >= p->capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmptyCharArray(struct charArray *p)
{
    if(p== NULL || p->data == NULL)
    {
        return 0;
    }

    
    if(p->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int toStringChar(struct charArray *p, struct charArray *outValue)
{
    if(p == NULL || p->data == NULL || outValue == NULL || p->capacity < 1)
    {
        return 0;
    }
       

    int neededCapacity = p->size + 1; 

    if(outValue->data == NULL || outValue->capacity < neededCapacity)
    {
        char *newData = malloc(neededCapacity * sizeof(char));
        if(newData == NULL)
        {
            return 0;
        }
           

        if(outValue->data != NULL)
        {
            free(outValue->data);
        }
            

        outValue->data = newData;
        outValue->capacity = neededCapacity;
    }


    for(int i = 0; i < p->size; i++)
    {
        outValue->data[i] = p->data[i];
    }
        

    outValue->data[p->size] = '\0';
    outValue->size = p->size;

    return 1;
}

int lazyFillCharArray(struct charArray *p)
{
    if(p == NULL || p->data == NULL ||  p->capacity <= 0)
    {
        return 0;
    }

    initRandom();

    char alphabet[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i =p->size;i < p->capacity;i++)
    {
        int randomNumber = rand() % 52;
        p->data[i] = alphabet[randomNumber];
    }

    p->size = p->capacity;

    return 1;

}

int foreachCharArray(struct charArray *p, void (*elementFunc)(char*))
{
    if(p==NULL || p->data == NULL || !elementFunc)
    {
        return 0;
    }
    
    for(int i =0;i<p->size;i++)
    {
        char *arrayPointer = &p->data[i];
        elementFunc(arrayPointer);
    }

    return 1;



}

// map/filter functions would return a new charArray
int mapCharArray(struct charArray *p, char (*mapFunc)(char),struct charArray *outValue)
{
    if(p == NULL || p->data == NULL || !mapFunc || outValue == NULL)
    {
        return 0;
    }

   free(outValue->data);

    outValue->data = malloc(p->size * sizeof(char));

    if (outValue->data == NULL)
    {
        outValue->size = 0;
        outValue->capacity = 0;

        return 0;
    }

    outValue->capacity = p->size;

    for (int i = 0; i < p->size; i++)
    {
        outValue->data[i] = mapFunc(p->data[i]);
    }

    outValue->size = p->size;

    return 1;
    


}

int filterCharArray(struct charArray *p, int (*filterFunc)(char), struct charArray *outValue)
{
    if(p == NULL || p->data == NULL || !filterFunc || outValue == NULL )
    {
        return 0;
    }

    free(outValue->data);

    int counter = 0;

    for (int i = 0; i < p->size; i++)
    {
      if(filterFunc(p->data[i]))
      {
        counter++;
      }
    }

    if(counter <= 0)
    {
        outValue->data = NULL;
        outValue->size = 0;
        outValue->capacity = 0;
        return 0;
    }
    

    outValue->data = malloc(counter * sizeof(char));

    if(outValue->data == NULL)
    {
        outValue->size = 0;
        outValue->capacity = 0;
        return 0;
    }

    int j = 0;
    for(int i = 0; i < p->size;i++)
    {
        if(filterFunc(p->data[i]))
        {
            outValue->data[j++] = p->data[i];
        }
    }

    outValue->capacity = counter;
    outValue->size = counter;

    return 1;


}

int sortCharArray(struct charArray *p)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    qsort(p->data, p->size, sizeof(char), compareChar);

    return 1;

}

int reverseCharArray(struct charArray *p)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    for(int i = 0; i < p->size / 2;i++)
    {
        swapChar(&p->data[i],&p->data[p->size-1-i]);
    }

    return 1;
}

int shuffleCharArray(struct charArray *p)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    initRandom();

    for(int i = 0;i < p->size;i++)
    {
        int randomIndex = i + rand() % (p->size - i);

        swapChar(&p->data[i],&p->data[randomIndex]);
    }

    return 1;

}

int printCharArray(struct charArray *p)
{
    if(p == NULL || p->data == NULL)
    {
        return 0;
    }

    for(int i = 0;i <p->size;i++)
    {
        printf("%c", p->data[i]); 
        if(i != p->size-1)
        {
            printf(",");  
        }

    }

    printf("\n");

    return 1;
}

int copyCharArray(struct charArray *p,struct charArray *outValue)
{
    if(p == NULL || p->data == NULL || outValue == NULL)
    {
        return 0;
    }

    free(outValue->data);

    outValue->capacity = 0;
    outValue->size = 0;
  

    outValue->data = malloc(p->size * sizeof(char));

    if(outValue->data == NULL)
    {

        return 0;

    }

  

    for(int i = 0;i < p->size;i++)
    {
        outValue->data[i] = p->data[i];
    }

    outValue->capacity = p->size;
    outValue->size = p->size;

    return 1;
}
