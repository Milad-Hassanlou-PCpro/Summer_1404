#include "curses.h"
#include <unistd.h>
#include <panel.h>

int main()
{
    initscr();
    noecho();
    WINDOW *win1 = newwin(5, 20, 5, 16);
    WINDOW *win2 = newwin(5, 20, 8, 19);

    box(win2, 0, 0);
    box(win1, 0, 0);
    mvwprintw(win1, 1, 1, "Window_1");
    mvwprintw(win2, 1, 1, "Window_2");
    PANEL *pan1 = new_panel(win1);
    PANEL *pan2 = new_panel(win2);
    update_panels();
    doupdate();
    sleep(2);
    hide_panel(pan1);
    hide_panel(pan2);
    sleep(2);
    printw("Hello. Use Numers 1 & 2 to see the panels , b & t to control panel 2 , q to quit ");
    refresh();
    sleep(2);
    char c;
    while ((c = getch()) != 'q')
    {
        switch (c)
        {
        case '1':
            show_panel(pan1);
            break;
        case '2':
            show_panel(pan2);
            break;
        case 'b':
            bottom_panel(pan2);
            break;
        case 't':
            top_panel(pan2);
            break;
        default:
            mvprintw(7, 3, "Invalid Input!");
            refresh();
            sleep(1);
            mvprintw(7, 3, "                ");
            refresh();
        }

        update_panels();
        doupdate();
    }

    delwin(win1);
    delwin(win2);
    return 0;
}