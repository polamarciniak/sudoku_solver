#include "plansza.h"

using namespace std;

int main()
{
    if(solve() == true)    print_sudoku();
    else    cout << "no solution";
}
