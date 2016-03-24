#include"Sudoku.h"

Sudoku::Sudoku()
{
    int empty[SIZE];
    memset(empty,0,sizeof(empty));
    setBoard(empty[]);
}
Sudoku::Sudoku(const int init_board[])
{
    setBoard(init_board[]);
}
void Sudoku::setBoard(const int set_board[])
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        board[i]=set_board[i];
    }
}
int getElemint(int index)
{
    return board[index];
}
