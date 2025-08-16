#include "curses.h"
#include <unistd.h>

int main()
{
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLUE);
    init_pair(2, COLOR_YELLOW, COLOR_WHITE);
    WINDOW* win = newwin(10,60,1,1);
    wrefresh(win);
    sleep(2);
    wattron(win,COLOR_PAIR(1)|A_BOLD);                //***
    wbkgd(win,COLOR_PAIR(2));
    box(win,0,0);
    mvwprintw(win,1,1,"Main Window");
    wattroff(win,COLOR_PAIR(1)|A_BOLD);               //**
    wrefresh(win);
    sleep(5);
}