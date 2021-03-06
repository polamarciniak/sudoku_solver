#ifndef PLANSZA
#define PLANSZA
#include "head.h"

using namespace std;

bool is_in_row (int row, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if(T[row][i] == val)  return true;
    }
    return false;
}

bool is_in_col (int col, int val)
{
    for(int i = 0; i < 9; i++)
    {
        if(T[i][col] == val)  return true;
    }
    return false;
}

bool is_in_square (int st_row, int st_col, int val)
{
    for(int i = 0; i < 3; i++)  //i for rows
    {
        for(int j = 0; j < 3; j++)  //j for columns
        {
            if(T[i+st_row][j+st_col] == val)  return true;
        }
    }
    return false;
}

bool is_valid (int row, int col, int val)
{
    return (!is_in_row(row, val) && !is_in_col(col, val) && !is_in_square(row - row%3, col - col%3, val));
}

bool find_empty(int &row, int &col)
{
    for(row = 0; row < 9; row++)
    {
        for(col = 0; col < 9; col++)
        {
            if(T[row][col] == 0)    return true;
        }
    }
    return false;
}

bool is_correct()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(!is_valid(i, j, T[i][j]))    return false;
        }
    }
    return true;
}

bool solve()
{
    int row, col;
    if(!find_empty(row, col))   return true;    //when array is full
    for(int val = 1; val <= 9; val++)
    {
        if(is_valid(row, col, val))
        {
            T[row][col] = val;

            if(solve()) return true;

            T[row][col] = 0;
        }
    }
    return false;
}


void print_sudoku()
{
    cout << "\n";
    for(int row = 0; row < 9; row++)
    {
        cout << " ";
        for(int col = 0; col < 9; col++)
        {
            if(col == 3 || col == 6)    cout << "| ";
            cout << T[row][col] << " ";
        }
        if(row == 2 || row == 5)    cout << "\n ------ ------- ------ ";
        cout << "\n";
    }
}
#endif // PLANSZA


