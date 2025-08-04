#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_EMPLOYEES 10

typedef struct
{
    int id;
    char name[20];
    int age;
} Employee;

void addWorker(Employee *workers, int *count, int *Id);
void menu(Employee *workers, int *count, int *Id);
void searchMenu(Employee *workers, int count);
void deleteWorker(Employee *workers, int *count);
int searchById(Employee *workers, int count);
Employee searchByName(Employee *workers, int count);
void showAllWorkers(Employee *workers, int count);


int main()
{
    Employee workers[MAX_EMPLOYEES];
    int counter = 0;
    int baseId = 404001;
    menu(workers, &counter, &baseId);
    return 0;
}

void menu(Employee *workers, int *count, int *Id)
{
    while (1)
    {
        int choose = 0;
        printf("-------MENU-------\n");
        printf("1-Add worker\n");
        printf("2-Delete Worker\n");
        printf("3-Search Worker\n");
        printf("4-Show All Workers\n");
        printf("5-exit\n");
        printf("Please Input a Number:");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            addWorker(workers, count, Id);
            break;
        case 2:
            deleteWorker(workers, count);
            break;
        case 3:
            searchMenu(workers, (*count));
            break;
        case 4:
            showAllWorkers(workers,(*count));
            break;
        case 5:
            return;

        default:
            printf("Invalide Input!");
        }
    }
}

void searchMenu(Employee *workers, int count)
{
    int choose = 0;
    printf("Please chose the type of search:\n");
    printf("1-Search by name\n");
    printf("2-Search by Id\n");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        Employee result = searchByName(workers, count);
        if (result.id != -1)
        {
            printf("Name: %s, Id: %d ,Age: %d\n", result.name, result.id, result.age);
        }
        else
        {
            printf("There is not such a worker!\n");
        }
        break;
    case 2:
        int targetId = searchById(workers, count);
        if (targetId != -1)
        {
            printf("Name: %s, Id: %d, Age: %d\n", (workers + targetId)->name, (workers + targetId)->id, (workers + targetId)->age);
        }
        else
        {
            printf("Worker with this Id is not found!\n");
        }
        break;
    default:
        printf("Invalid input!\n");
    }
}

void addWorker(Employee *workers, int *count, int *Id)
{
    if (*count < MAX_EMPLOYEES)
    {
        printf("Name:");
        scanf("%s",(workers + (*count))->name);
        printf("Age:");
        scanf("%d", &(workers + (*count))->age);
        (workers + (*count))->id = (*Id);
        printf("The worker signed in workers list.(ID:%d)\n", (*Id));
        (*count)++;
        (*Id)++;
    }
    else
    {
        printf("There's not enough scape to add a new worker!\n");
    }
    return;
}

void deleteWorker(Employee *workers, int *count)
{
    int indexResult = 0;
    if ((indexResult = searchById(workers, (*count))) != -1)
    {
        printf("Worker with this information is being deleted: ...\n");
        printf("Name: %s, Id: %d, Age: %d\n", (workers + indexResult)->name, (workers + indexResult)->id, (workers + indexResult)->age);
        for (int j = indexResult; j < (*count) - 1; j++)
        {
            workers[j] = workers[j + 1];
        }
        (*count)--;
        printf("Deleting completed!\n");
    }
    else
    {
        printf("Worker with this Id is not found!\n");
    }
    return;
}

int searchById(Employee *workers, int count)
{
    int targetId = 0;
    printf("Please input the Id of the worker:");
    scanf("%d", &targetId);
    for (int i = 0; i < count; i++)
    {
        if ((workers + (i))->id == targetId)
        {
            return i;
        }
    }
    return -1;
}

Employee searchByName(Employee *workers, int count)
{
    char targetName[20];
    printf("Name:");
    scanf("%s", targetName);
    for (int i = 0; i < count; i++)
    {
        if (_stricmp((workers + i)->name, targetName) == 0)
        {
            return *(workers + i);
        }
    }
    Employee notFound = {-1, "notFound", 0};
    return notFound;
}

void showAllWorkers(Employee *workers, int count)
{
    printf("All workers in list:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d-Id: %d, Name: %s, Age: %d\n", i+1,(workers+i)->id,(workers+i)->name,(workers+i)->age);
    }
    return;
}