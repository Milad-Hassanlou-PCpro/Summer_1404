#include "curses.h"
#include <unistd.h>

int main() {
    printf("Hello\n");
    sleep(2);
    initscr();
    printw("Hello From Ncurses from windows!");
    refresh();
    getch();
    endwin();
    printf("Goodbye\n");
    return 0;
}
