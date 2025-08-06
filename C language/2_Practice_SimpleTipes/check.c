#include<stdio.h>
#include<string.h>

int main()
{
    char input [20]="mohammah";
    int location = strcspn(input,"H");
    printf("Location Of the Character:%d\n",location);
    return 0;
}