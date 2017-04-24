#include<iostream>
using namespace std;
string gram[6];
gram[0]="E=E+T"
gram[1]="E=E";
gram[2]="T=T*F"
gram[3]="T=F";
gram[4]="F=N"
gram[5]="F=(E)";
string terms="+*()N$";
int table[6][6]={
    {1,-1,-1,1,-1,1},
    {1,1,-1,1,-1,1},
    {-1,-1,-1,,-1,1},
    {1,1,0,1,0,1},
    {1,1,0,1,0,1},
    {-1,-1,-1,-1,-1,0},
    };

void printStack(stack<char> myStack)
{
    queue<char> myQueue;
    while(!myStack.empty())
    {
        cout<<myStack.top;
    }
}
int givePrec(char a, char b)
{
    if(a>='0')&&(a<='9')
        a='N';
    if(b>='0')&&(b<='9')
        b='N';
    pos=terms.find_first_of(a);
    pos1=terms.find_first_of(b);
    if(pos==string::npos)||(pos==string::npos)
        return 1;

    return table[pos-1][pos1-1];
}
int accept(string str)
{
    stack<char> myStack;
    stack<char> stack2;
    string
    int i=0,step=0;
    myStack.push
    while(str[i]!='\0')
    {
        cout<<step++<<" ";
        cout<< left << setw(15) << setfill(' ')<<myStack;
        cout<< left << setw(5) << setfill(' ')<<str[i];
        cout<< right << setw(15) << setfill(' ')<<&str[i+1];
        prec=givePrec(myStack.top(),str[i]);
        if(prec<0)
        {
            myStack.push(str[i++]);
        }
        else if(prec>0)
        {
            stack2.
        }
    }
}
main()
{
    string str;
    cout<<"Enter string ";
    cin>>str;
    if(accept(str))
        cout<<"Accepted\n";
    else
        cout<<"Not Accepted\n";
}
