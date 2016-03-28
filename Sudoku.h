#include<iostream>
#include<cstring>
#define SIZE 81

using namespace std;
class Sudoku{
    public:
        Sudoku();
        Sudoku(const int init_board[]);
        
        void giveQuestion();//出題
        void readIn();
        void solve();
        void changeNum(int a,int b);//換數字
        void changeRow(int a,int b);//換大列
        void changeCol(int a,int b);//換大行
        void rotate(int n);//旋轉n*90度
        void flip(int n);//n=0,垂直鏡射;n=1,水平鏡射
        void transform();//再出題
        
        void setBoard(const int set_board[]);
        int getElement(int index);
        void printBoard();
    private:
        int _board[SIZE];
};
