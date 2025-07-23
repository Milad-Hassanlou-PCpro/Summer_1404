#include "operator.h"

int main()
{
    int chose_operator = 0, a = 0, b = 0;
    float result = 0;
    while (1)
    {
        printf("Choose the Operator:\n");
        printf("1-Sum\n");
        printf("2-Deduct\n");
        printf("3-Multiple\n");
        printf("4-Divide\n");
        printf("5-Print Last %d History\n", STORAGE_CAPACITY);
        printf("6-Exit\n");
        scanf("%d", &chose_operator);
    back:
        if (1 <= chose_operator && chose_operator <= 4)
        {
            printf("Please Input Tow Numbers:\n");
            scanf("%d %d", &a, &b);
            if (a < 0 || b < 0)
            {
                printf("Numbers must not be Negative!\n");
                goto back;
            }
        }

        switch (chose_operator)
        {
        case 1:
            result = sum(a, b);
            break;
        case 2:
            result = deduct(a, b);
            break;
        case 3:
            result = multiple(a, b);
            break;
        case 4:
            result = divide(a, b);
            break;
        case 5:
            printHistory();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid Choise!\n");
        }

        if (1 <= chose_operator && chose_operator <= 4)
        {
            printf("Result:%.2f\n", result);
        }
    }
}