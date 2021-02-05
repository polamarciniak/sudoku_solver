#include "head.h"
using namespace std;

int sizex, sizey;


int main()
{
    initscr();
    start_color();

    getmaxyx(stdscr, sizey, sizex);

    init_color_pairs();
    refresh();
    noecho();
    curs_set(0);

    WINDOW *sudoku;
    attron(COLOR_PAIR(3));
    write_entry();
    attroff(COLOR_PAIR(3));
    clear();
    refresh();

    echo();

    if(solve())
    {
        sudoku = create_window(11, 21, (sizey)/2-5, (sizex)/2-11, TRUE);
        print_window(sudoku);
        wgetch(sudoku);
        endwin();
        clear();
        refresh();
    }

    endwin();
    refresh();
    return 0;
}
