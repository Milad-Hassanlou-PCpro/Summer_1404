#include "curses.h"
#include <unistd.h>

int main()
{
    initscr();
    printw("Hello.");
    refresh();
    sleep(1);
    mvprintw(3, 10, "Today I'm studying ncurses.");
    refresh();
    sleep(1);
    mvprintw(6, 20, "the title of my study is:");
    refresh();
    sleep(1);
    mvprintw(7, 30, "text cleaners.");
    refresh();
    sleep(1);
    printw("(It's not really hard!):");
    refresh();
    sleep(1);
    mvprintw(10, 40, "thanks.");
    refresh();
    sleep(1);
    mvprintw(13, 50, "Goodbye.");
    refresh();
    sleep(2);
    //
    move(7,44);
    //clrtobot();
    clrtoeol();
    printw("*");
    refresh();
    sleep(1);
    //
    printw("I'm back.");
    refresh();
    sleep(2);
    endwin();
    return 0;
}