#include <iostream>
#include <stdbool.h>
using namespace std;

int T[9][9] = {
    {0, 6, 2, 9, 0, 3, 0, 0, 0},
    {4, 1, 3, 6, 0, 0, 9, 0, 7},
    {9, 5, 0, 7, 2, 4, 0, 1, 0},
    {0, 3, 0, 0, 6, 9, 8, 0, 0},
    {2, 8, 0, 0, 0, 0, 0, 9, 0},
    {6, 7, 0, 4, 0, 8, 1, 3, 0},
    {8, 2, 0, 5, 3, 6, 0, 0, 9},
    {0, 4, 6, 8, 0, 7, 2, 0, 0},
    {0, 0, 0, 1, 4, 0, 3, 0, 8}
};

/*int T[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};*/

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


