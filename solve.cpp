#include"Sudoku.h"

int main()
{
    Sudoku ss;
    ss.readIn();
    ss.solve();
    ss.printBoard();
    return 0;
}
