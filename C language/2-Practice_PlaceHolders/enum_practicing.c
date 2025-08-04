#include<stdio.h>

enum Gender{
    MAIL=2,
    FEMAIL=100,
    OTHER
};

int main()
{
    enum Gender gen = OTHER;
    printf("%d\n",gen);
}