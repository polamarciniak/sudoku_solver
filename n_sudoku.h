#ifndef N_SUDOKU
#define N_SUDOKU
#include "head.h"
using namespace std;

int T[9][9] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};
bool R[9][9] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};


WINDOW *create_window(int height, int width, int posy, int posx, bool border)
{
    WINDOW *nwin;
    nwin = newwin(height, width, posy, posx);
    if(border)
    {
        box(nwin, 0, 0);
    }
    wrefresh(nwin);
    return nwin;
}

void get_numbers(WINDOW *win)
{
    int c;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            c = wgetch(win);
            if(c == ' ')    T[i][j] = 0;
            else   if(c >= '1' && c <= '9')
            {
                T[i][j] = c-'0';
                R[i][j] = true;
            }
            curs_set(0);
            if(j == 8)
            {
                mvwprintw(win, i+1, (j+1)*2, "%c ", c);
            }
            else
            {
                curs_set(1);
                mvwprintw(win, i+1, (j+1)*2, "%c ", c);
            }
            wrefresh(win);
        }
    }
}

void write_entry()
{
    initscr();

    int maxy, maxx;

    getmaxyx(stdscr, maxy, maxx);

    move(maxy/2-10, maxx/2-7);
    printw("Sudoku Solver");

    move(maxy/2-7, maxx/2-27);
    printw("To start paste your incomplete 9x9 sudoku puzzle here:");
    move(maxy/2-6, maxx/2-13);
    printw("(use space as empty place)");
    move(maxy/2+8, maxx/2-22);
    printw("Then press any key twice to get your answer");


    move(maxy/2-4, maxx/2-30);
    WINDOW *inputwin = create_window(11, 21, (maxy)/2-4, (maxx)/2-11, TRUE);
    refresh();
    wrefresh(inputwin);

    get_numbers(inputwin);

    //curs_set(1);

    refresh();

    getch();

    endwin();
}

void write_no_success()
{

    initscr();

    int maxy, maxx;

    getmaxyx(stdscr, maxy, maxx);

    move(maxy/2-1, maxx/2-15);
    printw("Sorry, your sudoku puzzle is incorrect :/");

    refresh();

    getch();

    endwin();

    /*curs_set(1);
    echo();
    int maxy, maxx;

    getmaxyx(stdscr, maxy, maxx);

    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, 1, 2, "Sorry, your sudoku puzzle is incorrect :/");
    wattroff(win, COLOR_PAIR(3));

    wrefresh(win);*/
}

void print_window(WINDOW *win)
{

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(T[i][j] == 0)
            {
                wattron(win, COLOR_PAIR(1));
                mvwprintw(win, 1+i, 2+j*2, "  ");
                wattroff(win, COLOR_PAIR(1));
            }
            else if(R[i][j])
            {
                wattron(win, COLOR_PAIR(1));
                mvwprintw(win, 1+i, 2+j*2, "%d ", T[i][j]);
                wattroff(win, COLOR_PAIR(1));
            }
            else
            {
                wattron(win, COLOR_PAIR(3));
                mvwprintw(win, 1+i, 2+j*2, "%d ", T[i][j]);
                wattroff(win, COLOR_PAIR(3));
            }
        }
    }

    wrefresh(win);
}

void init_color_pairs()
{
    init_pair(1, COLOR_CYAN, 0);
    init_pair(2, COLOR_GREEN, 0);
    init_pair(3, COLOR_BLUE, 0);
    init_pair(4, COLOR_RED, 0);
    init_pair(5, COLOR_MAGENTA, 0);
    init_pair(6, COLOR_YELLOW, 0);

}

#endif
