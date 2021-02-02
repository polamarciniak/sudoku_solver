#include <ncurses.h>
#include <stdbool.h>
#include <iostream>
#include <stdio.h>

bool is_in_row (int row, int val);
bool is_in_col (int col, int val);
bool is_in_square (int st_row, int st_col, int val);
bool is_valid (int row, int col, int val);
bool find_empty(int &row, int &col);
bool solve();
bool is_correct();
void print_sudoku();

WINDOW *create_window(int height, int width, int posy, int posx, bool border);
void get_numbers(WINDOW *win);
void write_entry();
void print_window(WINDOW *win);
void init_color_pairs();
void write_no_success();
