#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#define SIZE 81
#define DLX_R 9*SIZE
#define DLX_C 4*SIZE
using namespace std;
class Sudoku{
    public:
        Sudoku();
        Sudoku(const int init_board[]);
        
        void giveQuestion();
        void readIn();
        void solveBacktrace();//solve by using backtrace
        void changeNum(int a,int b);
        void changeRow(int a,int b);//change group row(include 3 row)
        void changeCol(int a,int b);//change group col(include 3 col)
        void rotate(int n);//n*90 degree
        void flip(int n);//n=0:vertically;n=1,horizontally
        void transform();
        
        void setBoard(const int set_board[]);
        int getElement(int index);
        void printBoard();
        
        void solve();//solve by using DLX(Dancing Links and Algorithm X)
    private:
        struct Node
        {
            Node *up;
            Node *down;
            Node *left;
            Node *right;
            Node *root;//the head of each col
            int row;//the location of row 
            int nodesum;//the sum of each col
            int questionnum;
        };
        Node *nodes,*row,*col,*head;
        int rownum,colnum,nodecount;
        int *result,resultcount;
        void initDlx();
        void coverCol(Node *t);
        void uncoverCol(Node *t);
        bool dance(int k);
        void addNode(int r,int c);
        
        void printSolve();
        bool checkCorrect();
        bool checkQuestion();
        bool checkIndexCorrect(int index);
        void backtrace(int num);
        
        int _board[SIZE];
        int _zeronum;
        int _solvenum;
        int _solveboard[SIZE];
};
