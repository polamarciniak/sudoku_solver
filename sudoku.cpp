#include "head.h"
#include "n_sudoku.h"
#include "plansza.h"

/*using namespace std;

int main()
{
    if(solve() == true)    print_sudoku();
    else    cout << "no solution";
}*/

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
    refresh();
    getchar();
    clear();
    refresh();



    if(solve() == true) //&& is_correct() == true) //nie dziala??
    {
        sudoku = create_window(11, 21, (sizey)/2-5, (sizex)/2-11, TRUE);
        print_window(sudoku);
    }
    else    write_no_success();

    return 0;
}
