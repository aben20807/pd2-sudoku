#include"Sudoku.h"

int main()
{
    Sudoku ss;
    ss.readIn();
    //ss.changeNum(1,2);
    //ss.changeRow(0,2);
    ss.changeCol(0,2);
    ss.printBoard();
    return 0;
}
