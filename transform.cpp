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
    //ss.flip(0);
    ss.transform();
    //ss.printBoard();
    cout<<endl;
    if(ss.checkCorrect())
        cout<<"yes"<<endl;
    else 
        cout<<"no"<<endl;
    return 0;
}
