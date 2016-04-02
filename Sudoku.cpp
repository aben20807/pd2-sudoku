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
{//print out the _board[]
    int i;
    for(i=0;i<SIZE;i++)
    {
        cout<<_board[i];
        cout<<(((i+1)%9==0)?'\n':' ');
    }
}
void Sudoku::printSolve()
{//print out the answer which store in _solveboard[]
    int i;
    for(i=0;i<SIZE;i++)
    {
        cout<<_solveboard[i];
        cout<<(((i+1)%9==0)?'\n':' ');
    }
}
bool Sudoku::checkCorrect()
{//using to check whole board
    int i,num=0;
    int check_tmp[27];
    for(i=0;i<27;i++)check_tmp[i]=1;
    //#define DEBUG_2//test check output
    for(i=0;i<SIZE;i++)
    {//row check
        #ifdef DEBUG_2
            cout<<i<<'\t';
        #endif
        check_tmp[num]*=_board[i];
        if(i%9==8)
        {
            #ifdef DEBUG_2
                cout<<setw(2)<<num<<":"<<check_tmp[num]<<endl;
            #endif
            if(check_tmp[num]!=362880)
            {
                return false;
            }
            num++;
        }
    }
    for(i=0;i<SIZE;i+=((i+9>80&&i!=80)?(-71):9))
    {//col check
        #ifdef DEBUG_2
            cout<<i<<'\t';
        #endif
        check_tmp[num]*=_board[i];
        if(i+9>80)
        {
            #ifdef DEBUG_2
                cout<<setw(2)<<num<<":"<<check_tmp[num]<<endl;
            #endif
            if(check_tmp[num]!=362880)
            {
                return false;
            }
            num++;
        }
    }
    for(i=0;i<SIZE;i+=((i%3==2&&i!=26&&i!=53)?((i==20||i==23||i==47||i==50||i==74||i==77)?(-17):7):1))
    {//cell check
        #ifdef DEBUG_2
            cout<<i<<'\t';
        #endif
        check_tmp[num]*=_board[i];
        if(i==20||i==23||i==26||i==47||i==50||i==53||i==74||i==77||i==80)
        {
            #ifdef DEBUG_2
                cout<<setw(2)<<num<<":"<<check_tmp[num]<<endl;
            #endif
            if(check_tmp[num]!=362880)
            {
                return false;
            }
            num++;
        }
    }
}
bool Sudoku::checkQuestion()
{//because the question maybe wrong, solve after checking 
    int i;
    for(i=0;i<SIZE;i++)
    {
        if(_board[i]!=0)
        {
            if(checkIndexCorrect(i)==false)
            {
                return false;
            }
        }
    }
    return true;
}
bool Sudoku::checkIndexCorrect(int index)
{
    int col,row,cell,i,j;
    col=index%9;
    row=static_cast<int>(index/9);
    cell=(static_cast<int>(row/3))*3+(static_cast<int>(col/3));
    for(i=0,j=9*row;i<9;i++,j++)//row check
    {
        if(_board[index]==_board[j]&&j!=index)
        {//if check index has the same number then return false
            return false;
        }
    }
    for(i=0,j=col;i<9;i++,j+=9)//col check
    {
        if(_board[index]==_board[j]&&j!=index)
        {//if check index has the same number then return false
            return false;
        }
    }
    switch(cell)//cell check
    {//using switch to get the cell's first index
        case 0:
        case 1:
        case 2:
            j=cell*3;
            break;
        case 3:
        case 4:
        case 5:
            j=cell*3+18;
            break;
        case 6:
        case 7:
        case 8:
            j=cell*3+36;
            break;
    }
    for(i=0,j;i<9;i++,j+=((j%3==2)?7:1))
    {
        if(_board[index]==_board[j]&&j!=index)
        {//if check index has the same number then return false
            return false;
        }
    }
    return true;//if all correct return true
}
void Sudoku::backtrace(int num)
{
    int i,solve_count=0;
    /*if(num==SIZE)//can comment out to see all solutions
    {
        printBoard();
    }*/
    if(num==SIZE)//trace finish
    {
        for(i=0;i<SIZE;i++)
        {//store first solution to check have any other solution
            _solveboard[i]=_board[i];
        }
        _solvenum++;
        if(_solvenum>1)
        {//more than 1 solution
            return ;
        }
        else;
    }
    int col,row;
    col=num%9;
    row=static_cast<int>(num/9);
    if(_board[num]==0)//find where can insert number
    {
        for(i=1;i<=9;i++)
        {//insert number from 1 to 9
            _board[num]=i;
            if(checkIndexCorrect(num))
            {
                //cout<<num<<":"<<i<<endl;
                backtrace(num+1);
            }
        }
        _board[num]=0;//back to up one level's for loop
    }
    else
    {//if meet problem number, insert the next index
        backtrace(num+1);
    }
}
void Sudoku::giveQuestion()
{
    int give_board[SIZE]={0,0,0,0,0,0,0,1,0,
                        4,0,0,0,0,0,0,0,0,
                        0,2,0,0,0,0,0,0,0,
                        0,0,0,0,5,0,4,0,7,
                        0,0,8,0,0,0,3,0,0,
                        0,0,1,0,9,0,0,0,0,
                        3,0,0,4,0,0,2,0,0,
                        0,5,0,1,0,0,0,0,0,
                        0,0,0,8,0,6,0,0,0
    };
    /*int give_board[SIZE]={8,0,0,0,0,0,0,0,0,
                        0,0,3,6,0,0,0,0,0,
                        0,7,0,0,9,0,2,0,0,
                        0,0,0,0,0,7,0,0,0,
                        0,0,0,0,4,5,7,0,0,
                        0,0,0,1,0,0,0,3,0,
                        0,0,1,0,0,0,0,6,8,
                        0,0,8,5,0,0,0,1,0,
                        0,9,0,0,0,0,4,0,0
    };*/
    setBoard(give_board);
    transform();
    //printBoard();
}
void Sudoku::readIn()
{
    int i;
    int in_board[SIZE];
    _zeronum=0;
    for(i=0;i<SIZE;i++)
    {
        cin>>in_board[i];
        if(in_board[i]==0)//count the zero's number
        {
            _zeronum++;
        }
    }
    setBoard(in_board);
}
void Sudoku::solveBacktrace()//solve by using backtrace
{
    int solve_count=0;
    _solvenum=0;
    //cout<<_zeronum<<endl;
    if(checkQuestion()&&_zeronum>64)//there is no solution if numbers are less than 17 
    {
        cout<<2<<endl;
    }
    else if(checkQuestion())
    {
        backtrace(0);
        solve_count++;
        switch(_solvenum)
        {
            case 0://no solution
                cout<<0;
                break;
            case 1://only 1 solution
                cout<<1<<endl;
                printSolve();
                break;
            default://more than 1 solution
                cout<<2;
                break;
        }
    }
    else//problem is wrong
    {
        cout<<0;
    }
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
        //cout<<i<<" "<<j<<endl;
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
    n%=4;//n is 4 times for one cycle
    //cout<<n<<endl;
    int i,j;
    if(n==0);
    else if(n==1)
    { 
        int tmpBoard[SIZE];
        for(i=0;i<SIZE;i++)
        {
            tmpBoard[i]=_board[i];
        }
        for(i=0,j=8;i<SIZE;i++,j+=(((j+9)>80)?(-73):9))
        {
            _board[j]=tmpBoard[i];
        }
    }
    else if(n==2)
    {
        int tmpBoard[SIZE];
        for(i=0;i<SIZE;i++)
        {
            tmpBoard[i]=_board[i];
        }
        for(i=0,j=80;i<SIZE;i++,j--)
        {
            _board[i]=tmpBoard[j];
        }
    }
    else if(n==3)
    { 
        int tmpBoard[SIZE];
        for(i=0;i<SIZE;i++)
        {
            tmpBoard[i]=_board[i];
        }
        for(i=0,j=8;i<SIZE;i++,j+=(((j+9)>80)?(-73):9))
        {
            _board[i]=tmpBoard[j];
        }
    }
    else;
}
void Sudoku::flip(int n)
{
    int i,j,tmp;
    if(n==0)
    {//vertically flip
        for(i=0,j=72;i<36;i++,j+=((j%9==8)?(-17):1))
        {
            //cout<<i<<" "<<j<<endl; 
            tmp=_board[i];
            _board[i]=_board[j];
            _board[j]=tmp;
        }
    }
    else if(n==1)
    {//horizontally flip
        for(i=0,j=8;i<76;i+=((i%9==3)?6:1),j+=((j%9==5)?12:(-1)))
        {
            //cout<<i<<" "<<j<<endl; 
            tmp=_board[i];
            _board[i]=_board[j];
            _board[j]=tmp;
        }
    }
    else;
}
void Sudoku::transform()
{
    srandom(time(NULL));
    int n,a,b;
    n=random()%15+5;//random the change times
    //#define DEBUG_1//test random output
    while(n--)
    {
        #ifdef DEBUG_1
            cout<<n<<":"<<endl;
        #endif
        a=random()%9+1;
        b=random()%9+1;
        #ifdef DEBUG_1
            cout<<a<<" "<<b<<endl;
            printBoard();
        #endif
        changeNum(a,b);
        a=random()%3;
        b=random()%3;
        #ifdef DEBUG_1
            cout<<a<<" "<<b<<endl;
            printBoard();
        #endif
        changeRow(a,b);
        a=random()%3;
        b=random()%3;
        #ifdef DEBUG_1
            cout<<a<<" "<<b<<endl;
            printBoard();
        #endif
        changeCol(a,b);
        a=random()%101;
        #ifdef DEBUG_1
            cout<<a<<endl;
            printBoard();
        #endif
        rotate(a);
        a=random()%2;
        #ifdef DEBUG_1
            cout<<a<<endl;
            printBoard();
        #endif
        flip(a);
    }
    printBoard();
}
void Sudoku::initDlx()
{//use to initialize
    //cout<<DLX_R<<" "<<DLX_C<<endl;
    nodes=new Node[DLX_R*DLX_C];//create DLX board
    row=new Node[DLX_R];
    col=new Node[DLX_C+1];
    result=new int[DLX_R];
    int i;
    rownum=DLX_R;
    colnum=DLX_C;
    for(i=0;i<=colnum;i++)
    {
        col[i].up=col[i].down=col+i;
        col[i].left=col+(i+colnum)%(colnum+1);
        col[i].right=col+(i+1)%(colnum+1);
        col[i].nodesum=0;
    }
    head=col+colnum;
    for(i=0;i<rownum;i++)
    {
        row[i].up=row[i].down=row[i].left=row[i].right=row[i].root=row+i;
    }
    nodecount=0;
}
void Sudoku::addNode(int r,int c)
{//add node which is transformed from sudoke to Exact cover
    //cout<<r<<" "<<c<<endl;
    nodes[nodecount].up=col[c].up;
    nodes[nodecount].down=col+c;
    nodes[nodecount].left=row[r].left;
    nodes[nodecount].right=row+r;
    nodes[nodecount].row=r;
    nodes[nodecount].root=col+c;
    col[c].up=col[c].up->down=row[r].left=row[r].left->right=nodes+nodecount++;
    col[c].nodesum++;
}
void Sudoku::coverCol(Node *t)
{//temporarily remove one col
    //cout<<t->up<<"."<<t->down<<"."<<t->left<<"."<<t->right<<"."<<t->root<<endl;
    Node *p,*q;
    t->left->right=t->right;
    t->right->left=t->left;
    for(p=t->down;p!=t;p=p->down)
    {
        for(q=p->right;q!=p;q=q->right)
        {
            q->up->down=q->down;
            q->down->up=q->up;
            q->root->nodesum--;//the number of this col decrease
        }
    }
}
void Sudoku::uncoverCol(Node *t)
{//restore the col which has removed temporarily
    Node *p,*q;
    for(p=t->up;p!=t;p=p->up)
    {
        for(q=p->left;q!=p;q=q->left)
        {
            q->up->down=q;
            q->down->up=q;
            q->root->nodesum++;//the number of this col increases
        }
    }
    t->left->right=t;
    t->right->left=t;
}
bool Sudoku::dance(int k)
{
    if(head->right==head)
    {//get one solution
        int i,j;
        for(i=0;i<SIZE;i++)
        {//store first solution to check have any other solution
            j=result[i];
            _solveboard[j/9]=1+j%9;
        }
        _solvenum++;
        if(_solvenum>1)
        {//more than 1 solution
            return true;
        }
        else
        {//check is there have any other solution
            //cout<<k<<endl;
            resultcount=k;
            return false;
        }
    }
    Node *pmin,*p,*q;
    for(pmin=head->right,p=pmin->right;p!=head;p=p->right)
    {//find the col which has the minimal nodes
        if(pmin->nodesum>p->nodesum)
            pmin=p;
    }
    coverCol(pmin);//start cover from min col
    for(p=pmin->down;p!=pmin;p=p->down)
    {
        result[k]=p->row;
        for(q=p->right;q!=p;q=q->right)
        {
            coverCol(q->root);
        }
        if(dance(k+1))
        {
            return true;
        }
        for(q=p->left;q!=p;q=q->left)
        {
            uncoverCol(q->root);//back to up one level's for loop
        }
    }
    uncoverCol(pmin);
    return false;
}
int getRowIndex(int row_num)  
{
    int num=row_num%9;  
    int row_index=row_num/ 81;  
    return 81+row_index*9+num;  
}
int getColIndex(int row_num)  
{
    int num=row_num%9;
    int index=row_num/9;
    int col_index=index%9;  
    return 162+col_index*9+num;  
}
int getCellIndex(int row_num)  
{
    int num=row_num%9;
    int index=row_num/9; 
    int row_index=index/9;
    int col_index=index%9;
    int cell_index=int(row_index/3)*3+col_index/3;  
    return 243+cell_index*9+num;  
}
void Sudoku::solve()//solve by using DLX(Dancing Links and Algorithm X)
{
    int i,j,nodecount=0;
    initDlx();
    int index;
    for(i=0;i<DLX_R;i++)
    {
        index=static_cast<int>(i/9);
        //cout<<index<<":"<<_board[index]<<" "<<i%9<<endl;
        if(_board[index]-1==i%9)//add question first
        {//if _board[index] has been inserted number then add 4 corresponds in DLX board.
            nodecount++;
            //cout<<nodecount<<endl;
            int rowindex=i,colindex=index;
            addNode(rowindex,colindex);
            addNode(rowindex,getRowIndex(i));
            addNode(rowindex,getColIndex(i));
            addNode(rowindex,getCellIndex(i));
            col[i].questionnum++;//record the number of question in each col
        }
    }
    for(i=0;i<DLX_R;i++)
    {
        index=static_cast<int>(i/9);
        //cout<<col[i].questionnum<<endl;
        if(_board[index]==0&&col[i].questionnum==0)//add empty place
        {//if _board[index]==0 then add all possibility, 
         //i.e. assume insert form 1 to 9 in this grid, so it will have 9*4 correspond in DLX board.
         //BUT if this col has had question number then it do not need to insert again or it will waste time and space.
            nodecount++;
            //cout<<nodecount<<endl;
            int rowindex=i,colindex=index;
            addNode(rowindex,colindex);
            addNode(rowindex,getRowIndex(i));
            addNode(rowindex,getColIndex(i));
            addNode(rowindex,getCellIndex(i));
        }
    }
    _solvenum=0; 
    dance(0);
    switch(_solvenum)
    {
        case 0:
            cout<<0;
            break;
        case 1:
            cout<<1<<endl;
            printSolve();
            break;
        case 2:
            cout<<2;
            break;
    }
}
