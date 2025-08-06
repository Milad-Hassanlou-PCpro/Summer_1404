#include <stdio.h>
#include <conio.h> // برای getch و kbhit
#include <unistd.h>
#define MAX_NAME_SPACE 20
int main()
{
    //    float a = 10.2;
    //    printf("Amount:%d\n", a);
    //    printf("Amount:%ld\n", a);
    //    printf("Amount:%u\n", a);
    //    printf("Amount:%lu\n", a);
    //    printf("Amount:%x\n", a);
    //    printf("Amount:%X\n", a);
    //    printf("Amount:%o\n", a);
    //    printf("Amount:%e\n", a);
    //    printf("Amount:%E\n", a);
    //
    //    float result = 21 % 8;
    //    printf("Amount:%f\n", result);
    //    printf("Amount:%.2f\n", result);
    //   int hidden = 1;
    //////////////////////////////////////////////
    //////////////////////////////////////////////
    //   while (hidden != 0)
    //   {
    //       hidden = getch();
    //       if ('a' <= hidden && hidden <= 'z')
    //       {
    //           hidden -= 32;
    //       }
    //       printf("HIDDEN = %c   \r", hidden);
    //   }
    //   printf("\n");
    ///////////////////////////////////////////////
    ///////////////////////////////////////////////

    /**
     * this part do not work properly::::::false
     **/

    //   printf("Please Input Your Name:\n");
    //   printf("----");
    //   char name[20];
    //   scanf("%s", name);
    //   if (kbhit())
    //   {
    //       printf("\r");
    //   }
    //   printf("NAME :%s\n", name);
    //   return 0;
    //////////////////////////////////////////////
    //////////////////////////////////////////////
    //**************** Chat GPT *****************
    //    printf("Please Input Your Name:\n");
    //    printf("----");
    //
    //    char name[20];
    //    int i = 0;
    //    int firstKey = 1;
    //
    //    while (1)
    //    {
    //        // if (kbhit())
    //        // {
    //        char ch = getch();
    //
    //        //sleep(2);
    //
    //        if (firstKey)
    //        {
    //            printf("\r    \r");
    //            firstKey = 0;
    //        }
    //
    //        if (ch == '\r')
    //            break;
    //        if (i < sizeof(name) - 1)
    //        {
    //            name[i++] = ch;
    //            putchar(ch);
    //        }else{
    //            printf("\nNo enough space!");
    //            break;
    //        }
    //        // }
    //    }
    //    name[i] = '\0';
    //
    //    printf("\nNAME: %s\n", name);
    //    return 0;
    /////////////////////////////////////////////////////
    /////////////////////////////////////////////////////
    /*در این کد موارد زیر رعایت شده
     *1-قرار دادن حاشیه و محدوده با اسلش برای ورودی
     *2-پاک کردن محل حروف به محض زدن اولین حرف
     *3-استفاده از متغیر ماکرو برای کارکرد کلی و شناور کد
     *4-مشخص کردن پایان محدوده با | و وجود امکان زدن اینتر برای قبول شدن اسم با ذرفیت کامل
     *5-مشخص کردن نوع اسم دریافت شده به صورت کامل یا ناقص
     */
    printf("Please Input Your Name:\a\n");
    printf("//");
    for (int i = 0; i < MAX_NAME_SPACE; i++)
    {
        printf("-");
    }
    printf("//\r//");

    int count = 0;
    char name[MAX_NAME_SPACE + 1];
    char ch;
    int isComplete = 0;
    while (1)
    {
        if (count >= MAX_NAME_SPACE)
        {
            printf("|\b");
        }
        ch = getch();

        if (ch == 8) 
        {
            if (count > 0)
            {
                count--;
                printf("\b \b");
            }
            continue;
        }

        if (count < MAX_NAME_SPACE)
        {
            if (count == 0)
            {
                printf("                    \r//");
            }
            if (ch == '\r')
            {
                isComplete = 1;
                break;
            }
            name[count++] = ch;
            printf("%c", ch);
        }
        else if (ch == '\r')
        {
            isComplete = 1;
            break;
        }
        else
        {
            printf("\nRiched to full Space limit!\n");
            isComplete = 0;
            break;
        }
    }
    name[count] = '\0';

    if (isComplete)
    {
        printf("\nName: %s\n", name);
    }
    else
    {
        printf("Incompleted Name: %s\n", name);
    }
    return 0;
}
