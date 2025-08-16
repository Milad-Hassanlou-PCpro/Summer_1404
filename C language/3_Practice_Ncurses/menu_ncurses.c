#include <curses.h>

int main() {
    initscr();              // شروع curses
    noecho();               // جلوگیری از چاپ مستقیم ورودی
    curs_set(0);            // مخفی کردن مکان‌نما
    keypad(stdscr, TRUE);   // فعال کردن کلیدهای خاص مثل ↑ ↓

    char *choices[] = {
        "choice 1",
        "choice 2",
        "choice 3",
        "Exit"
    };
    int n_choices = sizeof(choices) / sizeof(char *);
    int highlight = 0;   // اولین گزینه برجسته باشد
    int choice = -1;
    int c;

    while (1) {
        // چاپ منو
        for (int i = 0; i < n_choices; i++) {
            if (i == highlight) {
                attron(A_REVERSE); // برجسته کردن
                mvprintw(2 + i, 2, "%s", choices[i]);
                attroff(A_REVERSE);
            } else {
                mvprintw(2 + i, 2, "%s", choices[i]);
            }
        }
        c = getch();

        switch (c) {
            case KEY_UP:
                highlight--;
                if (highlight < 0) highlight = n_choices - 1;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight >= n_choices) highlight = 0;
                break;
            case 10: // کلید Enter
                choice = highlight;
                break;
        }

        if (choice != -1) {
            mvprintw(10, 2, "You have choosen: %s", choices[choice]);
            refresh();
            if (choice == n_choices - 1) break; // اگر "خروج" انتخاب شد
            getch();
            choice = -1; // ریست برای انتخاب بعدی
        }
        refresh();
    }

    endwin();
    return 0;
}
