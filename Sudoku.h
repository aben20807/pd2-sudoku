#include<iostream>

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
        void changeRow(int a,int b);
        void changeCol(int a,int b);
        void rotate(int n);
        void flip(int n);
        void transform();
        
        void setBoard(const int set_board[]);
        int getElement(int index);
        void printBoard();
    private:
        int board[SIZE]
};
