#include "curses.h"
#include <unistd.h>

int main()
{
    initscr();

    nocbreak();
    printw("put a string! 1 :");
    refresh();
    char str1[20];
    getstr(str1);

    cbreak();
    printw("put a string! 2 :");
    refresh();
    char str2[20];
    getstr(str2);
    nocbreak();

    //nocbreak();
    noraw();
    printw("put a character 1 : ");
    refresh();
    char ch1;
    ch1 = getch();
    //scanw("%c",&ch1);

    //cbreak();
    raw();
    printw("put a character 2 : ");
    refresh();
    char ch2; 
    ch2 = getch();
    //scanw("%c",&ch2);
    //nocbreak();
    noraw();

    nocbreak();
    printw("put a number 1 : ");
    refresh();
    int num1;
    scanw("%d", &num1);

    cbreak();
    printw("put a number 2 : ");
    refresh();
    int num2;
    scanw("%d", &num2);
    nocbreak();

    sleep(2);
    mvprintw(10, 10, "str1: %s, srt2: %s, ch1: %c, ch2: %c, num1: %d, num2: %d", str1, str2, ch1, ch2, num1, num2);
    refresh();
    sleep(5);
    endwin();
    return 0;
}