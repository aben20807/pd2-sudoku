#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
//#include<vector>
#define SIZE 81

using namespace std;
class Sudoku{
    public:
        Sudoku();
        Sudoku(const int init_board[]);
        
        void giveQuestion();//出題
        void readIn();
        void solve();
        void changeNum(int a,int b);
        void changeRow(int a,int b);//change group row(include 3 row)
        void changeCol(int a,int b);//change group col(include 3 col)
        void rotate(int n);//n*90 degree
        void flip(int n);//n=0:vertically;n=1,horizontally
        void transform();
        
        void setBoard(const int set_board[]);
        int getElement(int index);
        void printBoard();
        bool checkCorrect();
        bool checkUnity(int index);
        bool checkIndexCorrect(int index);
        void backtrace(int num);
    private:
        int _board[SIZE];
        int _zeronum;
        //vector<int> _board;
        //_board.reserve(81);
};
