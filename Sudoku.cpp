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
bool Sudoku::checkCorrect()
{
    int i,num=0;
    int check_tmp[27];
    for(i=0;i<27;i++)check_tmp[i]=1;
    //#define DEBUG_2//test check output
    for(i=0;i<81;i++)
    {//row
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
    for(i=0;i<81;i+=((i+9>80&&i!=80)?(-71):9))
    {//col
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
    for(i=0;i<81;i+=((i%3==2&&i!=26&&i!=53)?((i==20||i==23||i==47||i==50||i==74||i==77)?(-17):7):1))
    {//cell
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
/*bool Sudoku::checkUnity(int arr[])
{
    int i;
    int unity[9];
    memset(unity,0,sizeof(unity));
    //for(i=0;i<9;i++)
    {
        //cout<<unity[i];
    }//cout<<endl;
    for(i=0;i<9;i++)
    {
        unity[arr[i]-1]++;
        //cout<<i<<":"<<arr[i]<<":"<<unity[arr[i]-1]<<endl;
    }
    for(i=0;i<9;i++)
    {
        cout<<unity[i]<<" ";
        if(unity[arr[i]-1]>1)return false;
    }
    cout<<endl;
    return true;
}*/
/*bool Sudoku::checkIndexCorrect(int index)
{//check index's row,col,cell correct
    int i,j,col,row,cell;
    int check_arr[9];
    col=index%9;
    row=static_cast<int>(index/9);
    cell=(static_cast<int>(row/3))*3+(static_cast<int>(col/3));
    for(i=0,j=9*row;i<9;i++,j++)//row
    {
        check_arr[i]=_board[j];
        //cout<<check_arr[i]<<" ";
    }//cout<<endl;
    if(checkUnity(check_arr)==false)
    {
        //cout<<"f:"<<index<<" ";
        return false;
    }
    for(i=0,j=col;i<9;i++,j+=9)
    {
        check_arr[i]=_board[j];
    }
    if(checkUnity(check_arr)==false)
    {
        return false;
    }
    switch(cell)
    {
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
        check_arr[i]=_board[j];
    }
    if(checkUnity(check_arr)==false)
    {
        return false;
    }
    //cout<<"T"<<endl;
    return true;
}*/
/*bool Sudoku::insert(int index)
{
    int j;
    for(j=1;j<=9;j++)
    {//insert 1 to 9
        _board[index]=j;
        if(checkIndexCorrect(i)==false&&j!=9)
        {
            //cout<<1<<" ";
            continue;
        }
        else if(checkIndexCorrect(i)==false&&index!=0)
        {
            _board[i]=0;
            //cout<<2<<" ";
            
            break;
        }
        else if(checkIndexCorrect(i)==false&&i==initnum)
        {
            //cout<<0<<endl;
            exit(1);
        }
        else
        {
            //cout<<j;
        }
    }
}*/
bool Sudoku::checkUnity(int index)
{
    int col,row,cell,i,j;
    col=index%9;
    row=static_cast<int>(index/9);
    cell=(static_cast<int>(row/3))*3+(static_cast<int>(col/3));
    for(i=0,j=9*row;i<9;i++,j++)//row
    {
        if(_board[index]==_board[j]&&j!=index)
        {
            return false;
        }
    }
    for(i=0,j=col;i<9;i++,j+=9)
    {
        if(_board[index]==_board[j]&&j!=index)
        {
            return false;
        }
    }
    switch(cell)
    {
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
        {
            return false;
        }
    }
    return true;
}
void Sudoku::backtrace(int num)
{
    if(num==81)
    {
        printBoard();
    }
    int col,row,i;
    col=num%9;
    row=static_cast<int>(num/9);
    if(_board[num]==0)
    {
        for(i=1;i<=9;i++)
        {
            _board[num]=i;
            if(checkUnity(num))
            {
                backtrace(num+1);
            }
        }
        _board[num]=0;
    }
    else
    {
        backtrace(num+1);
    }
}
void Sudoku::giveQuestion()
{
    /*int give_board[SIZE]={0,0,7,0,0,2,0,0,0,
                        0,1,0,0,0,0,0,0,9,
                        0,5,0,0,4,0,0,0,6,
                        0,9,0,0,0,0,0,0,1,
                        0,7,0,5,0,0,0,3,0,
                        6,0,0,0,0,7,0,5,0,
                        4,0,0,0,6,0,0,2,0,
                        8,0,0,0,0,0,0,1,0,
                        0,0,0,1,0,0,3,0,0
    };*/
    int give_board[SIZE]={8,0,0,0,0,0,0,0,0,
                        0,0,3,6,0,0,0,0,0,
                        0,7,0,0,9,0,2,0,0,
                        0,0,0,0,0,7,0,0,0,
                        0,0,0,0,4,5,7,0,0,
                        0,0,0,1,0,0,0,3,0,
                        0,0,1,0,0,0,0,6,8,
                        0,0,8,5,0,0,0,1,0,
                        0,9,0,0,0,0,4,0,0

    };
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
        if(in_board[i]==0)
        {
            _zeronum++;
        }
    }
    setBoard(in_board);
}
void Sudoku::solve()
{
    //cout<<_zeronum<<endl;
    if(_zeronum>64)
    {
        cout<<2<<endl;
    }
    else
    {
        backtrace(0);
    }
}
/*{
    int col,row,cell,flag,initnum;
    int i,j,k;
    //cout<<_zeronum<<endl;
    if(_zeronum>64)
    {
        cout<<2<<endl;
    }
    flag=1;
    for(i=0;i<SIZE;i++)
    {
        if(_board[i]==0)//if empty
        {
            if(flag)
            {//record the first 0 element's index
                initnum=i;
                flag=0;
            }
            col=i%9;
            row=static_cast<int>(i/9);
            cell=(static_cast<int>(row/3))*3+(static_cast<int>(col/3));
            //cout<<row<<" "<<col<<" "<<cell<<endl;
            for(j=1;j<=9;j++)
            {//insert 1 to 9
                _board[i]=j;
                if(checkIndexCorrect(i)==false&&j!=9)
                {
                    //cout<<1<<" ";
                    continue;
                }
                else if(checkIndexCorrect(i)==false&&i!=0)
                {
                    _board[i]=0;
                    //cout<<2<<" ";
                    i--;
                    break;
                }
                else if(checkIndexCorrect(i)==false&&i==initnum)
                {
                    //cout<<0<<endl;
                    exit(1);
                }
                else
                {
                    //cout<<j;
                }
            }
        }
    }
}*/
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
    {
        for(i=0,j=72;i<36;i++,j+=((j%9==8)?(-17):1))
        {
            //cout<<i<<" "<<j<<endl; 
            tmp=_board[i];
            _board[i]=_board[j];
            _board[j]=tmp;
        }
    }
    else if(n==1)
    {
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
    n=random()%15+5;
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
