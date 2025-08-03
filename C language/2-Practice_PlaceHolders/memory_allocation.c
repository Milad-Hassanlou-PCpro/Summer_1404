#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *ptr = malloc(2 * sizeof(int));
    int *intPtr = (int *)ptr;
    char *chPtr = (char *)ptr;
    intPtr[0] = 6;
    intPtr[1] = 7;
    for(int i=0;i<8;i++){
        printf("%x\n",chPtr[i]);
    }
    return 0;
}