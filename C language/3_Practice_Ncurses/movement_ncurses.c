#include"curses.h"
#include <unistd.h>
int main()
{
    initscr();
    int row,column;
    getmaxyx(stdscr,row,column);
    printw("Hello.");
    refresh();
    sleep(1);
    mvprintw(0,(column-1-3),"How");
    sleep(1);
    refresh();
    mvprintw(row-1,0,"are");
    sleep(1);
    refresh();
    mvprintw(row-1,(column-1-4),"you?");
    sleep(1);
    refresh();
    sleep(3);
    endwin();
}