#include <curses.h>
#include <panel.h>
#include <unistd.h>

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // ساخت سه پنجره و پنل‌ها
    WINDOW *win1 = newwin(10, 30, 2, 5);
    WINDOW *win2 = newwin(10, 30, 4, 10);
    WINDOW *win3 = newwin(10, 30, 6, 15);

    box(win1, 0, 0); mvwprintw(win1, 1,1,"Panel 1"); wrefresh(win1);
    box(win2, 0, 0); mvwprintw(win2, 1,1,"Panel 2"); wrefresh(win2);
    box(win3, 0, 0); mvwprintw(win3, 1,1,"Panel 3"); wrefresh(win3);
     
    sleep(2);
    refresh();
    sleep(2);

    PANEL *pan1 = new_panel(win1);
    PANEL *pan2 = new_panel(win2);
    PANEL *pan3 = new_panel(win3);

    update_panels();
    doupdate();

    sleep(2);           //***
    int ch;
    mvprintw(0,0,"Press 1/2/3 to bring panel to top, h to hide, s to show, q to quit");
    refresh();
    sleep(2);           //***

    while((ch = getch()) != 'q') {
        switch(ch) {
            case '1': top_panel(pan1); break;
            case '2': top_panel(pan2); break;
            case '3': top_panel(pan3); break;
            case 'h': hide_panel(pan2); break;  // فقط پنل دوم مخفی شود
            case 's': show_panel(pan2); break;  // پنل دوم دوباره نمایش داده شود
        }
        update_panels();
        doupdate();
    }

    del_panel(pan1); del_panel(pan2); del_panel(pan3);
    delwin(win1); delwin(win2); delwin(win3);
    endwin();
    return 0;
}
