#include <stdio.h>
#include <string.h>

union Person{
    int id;
    char name [10];
};
int main()
{
    union Person man;
    union Person *manPtr = & man;
    strcpy(manPtr->name,"abcdefghi");
    manPtr->id=-6;
    char* chPtr =(char*)&man;
    
    for(int i=0;i<10;i++){
        printf("%X\n",*(chPtr+i));
    }
    printf("Name: %s\n",man.name);
    printf("Name: %d\n",man.id);
    return 0;

}