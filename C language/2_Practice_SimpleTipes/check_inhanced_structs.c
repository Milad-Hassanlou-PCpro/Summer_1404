#include<stdio.h>
#include<string.h>

struct capital {
    char name [20];
    int age;
};

struct country{
    char name[20];
    struct capital center[2];
    long population;
};



int main()
{
    struct country country[2];
    strcpy((*country).name,"Iran");
    strcpy(country[0].center->name,"Tehran");
    country->center->age=8000;
    return 0;
}