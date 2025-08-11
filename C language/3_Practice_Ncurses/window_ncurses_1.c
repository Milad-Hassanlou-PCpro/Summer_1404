#include "curses.h"
#include <unistd.h>

int main()
{
    initscr();
    WINDOW *win1 = newwin(5, 20, 10, 0);
    box(win1, 0, 0);
    wrefresh(win1);
    sleep(3);
    WINDOW *win2 = newwin(5, 20, 10, 60);
    box(win2, 0, 0);
    wrefresh(win2);
    sleep(3);
    mvwprintw(win1, 1, 1, "Hello");
    wrefresh(win1);
    sleep(2);
    wclear(win1);
    box(win1, 0, 0); //
    wrefresh(win1);
    mvwprintw(win1, 1, 1, "fName: ");
    wrefresh(win1);
    sleep(1);
    mvwprintw(win2, 1, 1, "lName: ");
    wrefresh(win2);
    sleep(1);
    char fName[20];
    char lName[20];
    wgetnstr(win1, fName, 20);
    box(win1,0,0);
    wrefresh(win1);
    wgetnstr(win2, lName, 20);
    box(win2,0,0);
    wrefresh(win2);
    WINDOW *winResult = newwin(5, 40, 20, 20);
    box(winResult, 0, 0);
    wrefresh(winResult);
    sleep(2);
    mvwprintw(winResult, 2, 1, "fName: %s,lName: %s", fName, lName);
    wrefresh(winResult);
    sleep(5);
    wclear(winResult);
    wrefresh(winResult);
    delwin(winResult);
    
    WINDOW * winEnd =newwin(20,60,1,5);
    box(winEnd,0,0);
    mvwprintw(winEnd,10,27,"goodBye");
    wrefresh(winEnd);
    sleep(5);
    endwin();
    return 0;
}