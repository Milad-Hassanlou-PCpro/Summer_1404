#include "curses.h"
#include <unistd.h>
int main()
{
    initscr();
    nodelay(stdscr, TRUE);
    char ch1;
    char ch2;
    char ch3;
    char ch4;
    printw("\nInput a char 1 : ");
    refresh();
    ch1 = getch();
    //
    sleep(2);
    //
    printw("\nInput a char 2 : ");
    refresh();
    ch2 = getch();
    printw("\nInput a char 3 : ");
    refresh();
    ch3 = getch();
    printw("\nInput a char 4 : ");
    refresh();
    ch4 = getch();
    sleep(2);
    printw("\nch1:%c, ch2:%c, ch3:%c, ch4:%c", ch1, ch2, ch3, ch4);
    refresh();
    sleep(5);
    endwin();
    return 0;
}