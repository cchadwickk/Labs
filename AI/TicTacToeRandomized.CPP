#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void clrscr(){
    for(int i=0; i<20; i++)
        cout<<"\n";
}

class board{
public:
    int a[10][10];
    int dim;
    board(int n)
    { //TODO: MAKE A VARIABLE BOARD SIZE
        dim = 3;
        for(int i=0; i<dim; i++)
            for(int j=0; j<dim; j++)
                a[i][j] = 0;
    }

    void drawline(int n)
    {
        for(int i=0; i<n; i++)
            cout<<"- ";
        cout<<"\n";
    }

    void disp()
    {
        clrscr();
        for(int i=0; i<dim; i++)
        {
            for(int j=0; j<dim; j++)
            {
                if(a[i][j] == 0)
                    cout<<" ";
                else if(a[i][j]==1)
                    cout<<"O";
                else if(a[i][j]==2)
                    cout<<"X";
                if(j != dim-1)
                    cout<<"|";
            }
            cout<<"\n";
            if(i != dim-1)
                drawline(3);
        }
    }

    void disparr()
    {
        for(int i=0; i<dim; i++){
            for(int j=0; j<dim; j++)
                cout<<a[i][j];
            cout<<endl;
        }
    }
}b(3);

void user(int frst)
{
    int inp,i,j;
    cout<<"Input: ";
    cin>>inp;
    inp--;
    i=inp/3;
    j=inp%3;
    if(b.a[i][j] == true)
    {
        cout<<"INVALID OPTION\n";
        user(frst);
        exit(0);
    }
    else
    {
        b.a[i][j]=1+frst;
    }
    b.disp();
}

void aiRand(int frst, int turn)
{
    int val, i, j, x;

    if(b.a[1][1]==0)
    {
        b.a[1][1]=2-frst;
        return;
    }

    srand(time(NULL));
    val = rand() % (9-turn);
    cout<<val;
    for(int x=0; x<=val; x++)
    {
        i = x/3;
        j = x%3;
        if(b.a[i][j]!=0)
            val++;
    }

    i = val/3;
    j = val%3;
    cout<<endl<<val;
    b.a[i][j]=2-frst;
    b.disp();
}

int check(int x, int a, int b, int c)
{
    if(((a==x)&&(b==x)||(c==x)&&(b==x)||(a==x)&&(c==x))&&(a+b+c==x*2))
    {
        if(!a)
            return 0;
        else if(!b)
            return 1;
        else if(!c)
            return 2;
    }
    else return -1;
}

int checkThreat(int toChck, int &m, int &n)
{
    int retval1, retval2;
    for(int i=0; i<b.dim; i++)
    {
        retval1 = check(toChck, b.a[i][0], b.a[i][1], b.a[i][2]);
        retval2 = check(toChck, b.a[0][i], b.a[1][i], b.a[2][i]);
        if(retval1>-1)
        {
            m=i;n=retval1;
            return true;
        }
        else if(retval2>-1)
        {
            m=retval2;n=i;
            return true;
        }
    }
    retval1 = check(toChck, b.a[0][0], b.a[1][1], b.a[2][2]);
    retval2 = check(toChck, b.a[0][2], b.a[1][1], b.a[2][0]);
    if(retval1>-1)
    {
            m=retval1;
            n=retval1;
            return true;
    }
    else if(retval2>-1)
    {
            m=0+retval2;
            n=2-retval2;
            return true;
    }
    return false;
}

void aiReal(int frst, int turn)
{
    int i,j,retval;
    retval=checkThreat(2-frst, i, j);   //TO CHECK FOR WINNING COMBI
    if(retval){
        b.a[i][j] = 2-frst;
        return;
    }
    retval = checkThreat(1+frst, i, j);     //TO CHECK FOR OPP. WINNING COMBI
    if(retval){
        b.a[i][j] = 2-frst;
        return;
    }
    aiRand(frst, turn);
}

void showwin(int frst, int i, int j)
{
    if(b.a[i][j]==2-frst)
        cout<<"AI WON!!";
    else
        cout<<"YOU   WON!!";
    exit(0);

}

int checkIfEnd(int frst)
{
    int sum,sum1;
    for(int i=0;i<b.dim;i++)
    {
        if((b.a[i][0]>0)&&(b.a[i][0]==b.a[i][1])&&(b.a[i][1]==b.a[i][2]))
            showwin(frst, i, 0);

        else if((b.a[0][i]>0)&&(b.a[0][i]==b.a[1][i])&&(b.a[1][i]==b.a[2][i]))
            showwin(frst, 0, i);
    }

    if((b.a[0][0]>0)&&(b.a[0][0]==b.a[1][1])&&(b.a[1][1]==b.a[2][2]))
        showwin(frst, 1, 1);

    if((b.a[0][2]>0)&&(b.a[0][2]==b.a[1][1])&&(b.a[1][1]==b.a[2][0]))
        showwin(frst, 1, 1);
}

main()
{
    int frst;
    cout<<"First move ?: 0 = User, 1 = AI \n";
    cin>>frst;  //AI = 2-FRST, USER = 1+FRST
    int turn = 0;
    b.disp();
    while(turn < 9)
    {
        if((turn+frst) % 2 == 0)
            user(frst);
        else{
            aiReal(frst, turn);
            b.disp();
        }
        checkIfEnd(frst);
        turn++;
    }
    return 0;
}
