#include "curses.h"
#include <unistd.h>

int main() {
    initscr();
    printw("Hello");
    int row, column;
    getmaxyx(stdscr,row,column);
    //printw("Rows:%d,Columns:%d",row,column);
    //refresh();
    move((row/2),((79-1)/2));
    printw("*");
    refresh();
    sleep(2);
    move(5,15);
    printw("222222222222 Ncurses from windows!");
    refresh();
    getch();
    sleep(1);
    endwin();
    return 0;
}
