#include"curses.h"
#include<unistd.h>
#include<panel.h>

int main()
{
    initscr();
    WINDOW* win = newwin(5,10,2,2);
    box(win,0,0);
    //wrefresh(win);
    sleep(2);
    PANEL* pan = new_panel(win);
    update_panels();
    doupdate();
    sleep(2);
    refresh();
    sleep(2);
    delwin(win);
    return 0;
}