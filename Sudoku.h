#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#define SIZE 81

using namespace std;
class Sudoku{
    public:
        Sudoku();
        Sudoku(const int init_board[]);
        
        void giveQuestion();
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
        
    private:
        void printSolve();
        bool checkCorrect();
        bool checkProblem();
        bool checkIndexCorrect(int index);
        void backtrace(int num);
        
        int _board[SIZE];
        int _zeronum;
        int _solvenum;
        int _solveboard[SIZE];
};
