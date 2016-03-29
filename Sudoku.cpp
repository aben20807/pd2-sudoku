#include"Sudoku.h"

Sudoku::Sudoku()
{
    int empty[SIZE];
    memset(empty,0,sizeof(empty));
    setBoard(empty);
}
Sudoku::Sudoku(const int init_board[])
{
    setBoard(init_board);
}
void Sudoku::setBoard(const int set_board[])
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        _board[i]=set_board[i];
    }
}
int Sudoku::getElement(int index)
{
    return _board[index];    
}
void Sudoku::printBoard()
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        cout<<_board[i];
        cout<<(((i+1)%9==0)?'\n':' ');
    }
}
void Sudoku::giveQuestion()
{
    int give_board[SIZE]={0,0,7,0,0,2,0,0,0,
                    0,1,0,0,0,0,0,0,9,
                    0,5,0,0,4,0,0,0,6,
                    0,9,0,0,0,0,0,0,1,
                    0,7,0,5,0,0,0,3,0,
                    6,0,0,0,0,7,0,5,0,
                    4,0,0,0,6,0,0,2,0,
                    8,0,0,0,0,0,0,1,0,
                    0,0,0,1,0,0,3,0,0
    };
    setBoard(give_board);
    printBoard();
}
void Sudoku::readIn()
{
    int i;
    int in_board[SIZE];
    for(i=0;i<SIZE;i++)
    {
        cin>>in_board[i];
    }
    setBoard(in_board);
}
void solve()
{

}
void Sudoku::changeNum(int a,int b)
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        if(_board[i]==a)
        {
            _board[i]=b;
            continue;
        }
        if(_board[i]==b)
        {
            _board[i]=a;
            continue;
        }
    }
}
void Sudoku::changeRow(int a,int b)
{
    int i,j,tmp;
    for(i=a*27,j=b*27;i<a*27+27;i++,j++)
    {
        tmp=_board[i];
        _board[i]=_board[j];
        _board[j]=tmp;
    }
}
void Sudoku::changeCol(int a,int b)
{
    int i,j,tmp;
    for(i=a*3,j=b*3;i<a*3+75;i+=((i%3==2)?7:1),j+=((j%3==2)?7:1))
    {
        //cout<<i<<" "<<j<<endl;
        tmp=_board[i];
        _board[i]=_board[j];
        _board[j]=tmp;
    }
}
void Sudoku::rotate(int n)
{
    n%=4;
    //cout<<n<<endl;
    int i,j,tmp;
    int tmpBoard[SIZE];
    for(i=0;i<SIZE;i++)
    {
        tmpBoard[i]=_board[i];
    }
    if(n==0);
    else if(n==1)
    { 
        for(i=0,j=8;i<SIZE;i++,j+=(((j+9)>80)?(-73):9))
        {
            _board[j]=tmpBoard[i];
        }
    }
    else if(n==2)
    {
        for(i=0,j=80;i<SIZE;i++,j--)
        {
            _board[i]=tmpBoard[j];
        }
    }
    else if(n==3)
    { 
        for(i=0,j=8;i<SIZE;i++,j+=(((j+9)>80)?(-73):9))
        {
            _board[i]=tmpBoard[j];
        }
    }
    else;
}
