#include"curses.h"
# include<unistd.h>

int main(){
    initscr();
    WINDOW* win = newwin(5,10,5,5);
    box(win,0,0);
    wnoutrefresh(win);
    WINDOW* der_win = derwin(win,3,5,1,1);
    box(der_win,0,0);
    wnoutrefresh(der_win);
    mvwprintw(win,1,1,"Hello");
    wnoutrefresh(win);
    sleep(2);
    doupdate();
    sleep(2);
    mvwin(win,3,1);
    wresize(win,10,20);
    wclear(win);
    box(win,0,0);
    wrefresh(win);
    sleep(5);
    box(der_win,0,0);
    wrefresh(der_win);
    sleep(5);
    delwin(win);
    delwin(der_win);
    return 0;
}