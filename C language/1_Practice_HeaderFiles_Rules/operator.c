#include "operator.h"
// #include <stdio.h>
// #include <string.h>

typedef struct
{
    char history[50];
    float result;
} Storage;

int saveCount = 0;
Storage storArr[20];

void add_to_storage(char text[10], float result)
{
    if (saveCount <= STORAGE_CAPACITY)
    {
        strcpy(storArr[saveCount].history, text);
        storArr[saveCount].result = result;
        saveCount++;
    }
    else
    {
        for (int i = 0; i < STORAGE_CAPACITY - 1; i++)
        {
            storArr[i] = storArr[i + 1];
            strcpy(storArr[i].history, text);
            storArr[i].result = result;
        }
    }
}

float sum(int a, int b)
{
    float result = a + b;
    char text[10];
    sprintf(text, "%d + %d", a, b);
    add_to_storage(text, result);
    return result;
}

float deduct(int a, int b)
{
    float result = a - b;
    char text[10];
    sprintf(text, "%d - %d", a, b);
    add_to_storage(text, result);
    return result;
}

float multiple(int a, int b)
{
    float result = a * b;
    char text[10];
    sprintf(text, "%d * %d", a, b);
    add_to_storage(text, result);
    return result;
}

float divide(int a, int b)
{
    if (b == 0)
    {
        printf("Devision by Zero Error!\n");
    }
    else
    {
        float result = a / (float)b;
        char text[10];
        sprintf(text, "%d / %d", a, b);
        add_to_storage(text, result);
        return result;
    }
}

void printHistory()
{
    if (saveCount == 0)
    {
        printf("Nothing as Histopry.\n");
    }
    else
    {
        for (int j = 0; j < saveCount; j++)
        {
            printf("%d) %s --> %f\n", (j + 1), storArr[j].history, storArr[j].result);
        }
    }
    printf("\n");
}