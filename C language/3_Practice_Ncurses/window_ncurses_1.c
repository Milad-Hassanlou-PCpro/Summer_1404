#include"curses.h"
#include <unistd.h>

int main()
{
    initscr();
    WINDOW *win1 = newwin(10,20,3,6);
    box(win1,0,0);
    wrefresh(win1);
    sleep(3);
    int linesWin,columsWin,yBegin,xBegin;
    getmaxyx(win1,linesWin,columsWin);
    getbegyx(win1,yBegin,xBegin);
    printw("Linesof window: %d, Columns of window: %d, ybegin: %d, xBegine: %d",linesWin,columsWin,yBegin,xBegin);
    refresh();
    sleep(10);
    endwin();
    return 0;
}