#include"Sudoku.h"

int main()
{
    Sudoku ss;
    ss.readIn();
    //ss.changeNum(1,2);
    //ss.changeRow(0,2);
    //ss.changeCol(0,2);
    //ss.rotate(8);
    //ss.flip(0);
    //ss.flip(1);
    ss.transform();
    //ss.printBoard();
    cout<<endl;
    return 0;
}
