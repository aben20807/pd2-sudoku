#include"Sudoku.h"

int main()
{
    Sudoku ss;
    //while(1)
    {
        //ss.readIn();
        //ss.printBoard();
        ss.giveQuestion();
        cout<<endl;
        ss.transform();
        cout<<endl;
        //ss.solve();
        ss.solve();
    }
    //ss.printBoard();
    return 0;
}
