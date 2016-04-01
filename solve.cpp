#include"Sudoku.h"

int main()
{
    Sudoku ss;
    //while(1)
    {
        ss.readIn();
        ss.printBoard();
        ss.transform();
        cout<<endl;
        ss.solve();
    }
    //ss.printBoard();
    return 0;
}
