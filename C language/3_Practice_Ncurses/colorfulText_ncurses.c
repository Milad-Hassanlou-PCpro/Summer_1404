#include "curses.h"
#include <unistd.h>

int main() {
    initscr();
    printw("Hello");
    int row, column;
    getmaxyx(stdscr,row,column);
    printw("getxaxyx->row:%d, column:%d\n",row,column);
    printw("itself-> row%d, column%d\n",LINES,COLS);
    start_color();
    init_pair(1,COLOR_BLUE,COLOR_RED);
    init_pair(2,COLOR_BLACK,COLOR_YELLOW);
    refresh();

    attron(COLOR_PAIR(1));
    move((row/2),((79-15)/2));
    printw("How are you?");
    refresh();
    sleep(2);
    move(5,25);
    printw("Ha! ha! ha! Don't worry.");
    refresh();
    attroff(COLOR_PAIR(1));
    attron( COLOR_PAIR(2));
    move(6,35);
    scanw("%s",NULL);
    attroff(COLOR_PAIR(2));
    sleep(1);
    endwin();
    return 0;
}
