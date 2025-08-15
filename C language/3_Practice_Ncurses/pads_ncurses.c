#include <curses.h>
#include <unistd.h>

int main()
{
    initscr();
    noecho();
    cbreak();

    // ساخت پد 200 سطری و 100 ستونی
    WINDOW *pad1 = newpad(200, 100);
    WINDOW *pad2 = newpad(24,80); // empty pad for erasing

    // نوشتن متن در پد
    for (int i = 0; i < 200; i++)
    {
        mvwprintw(pad1, i, 0, "this line is the %d line of pad", i);
    }

    prefresh(pad1, 0, 0, 0, 0, 20, 75);
    sleep(2);
    prefresh(pad2, 0, 0, 0, 0, 20, 75);
    sleep(2);
    prefresh(pad1, 1, 0, 1, 1, 20, 75);
    sleep(2);
    prefresh(pad2, 0, 0, 1, 1, 20, 75);
    sleep(2);
    prefresh(pad1, 2, 0, 2, 2, 20, 75);
    sleep(2);
    prefresh(pad2, 0, 0, 2, 2, 20, 75);
    sleep(2);
    prefresh(pad1, 3, 0, 3, 3, 20, 75);
    sleep(2);
    prefresh(pad2, 0, 0, 3,3, 20, 75);

    sleep(5);

    delwin(pad1);
    delwin(pad2);
    endwin();
    return 0;
}
