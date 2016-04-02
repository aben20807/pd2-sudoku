#include"Sudoku.h"

int main()
{
    Sudoku ss;
    //while(1)
    {
        ss.readIn();
        ss.printBoard();
        //ss.transform();
        cout<<endl;
        //ss.solve();
        ss.solve2();
    }
    //ss.printBoard();
    return 0;
}
