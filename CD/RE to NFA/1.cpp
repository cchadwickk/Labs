#include<iostream>
#include<string.h>
#include"inToPost.h"
#include"stack.h"
#define noOfOps 4
#define noOfStates 20
using namespace std;

void addConn(int &addTo, int toAdd)
{
    if(addTo<0){
        addTo=toAdd;
        return;
    }
    addTo=addTo*10+toAdd;
}

op moveConns(op a,int toMove=1)
{
    for(int i=0;i<a.final;i++)
    {
        for(int j=0;j<noOfOps;j++)
        {
            if(a.table[i][j]>=0)
                a.table[i+toMove][j]=a.table[i][j]+toMove;
            else
                a.table[i+toMove][j]=a.table[i][j];
        }
    }
    a.final+=toMove;
    for(int i=0;i<toMove;i++)
    {
        for(int j=0;j<noOfOps;j++)
            a.table[i][j]=-1;
    }
    return a;
}

op copyAfter(op dest, op src)
{
    for(int i=0;i<=src.final;i++)
    {
        for(int k=0;k<noOfOps+1;k++)
        {
            if(src.table[i][k]>=0)
                dest.table[dest.final+i+1][k]=src.table[i][k]+dest.final+1;
            else
                dest.table[dest.final+i+1][k]=-1;
        }
    }
    dest.final=dest.final+src.final+1;
    return dest;
}

op applyKleene(op a)
{
    a=moveConns(a);
    a.final++;
    for(int i=0;i<=noOfOps;i++)
        a.table[a.final][i]=-1;
    addConn(a.table[0][noOfOps],1);
    addConn(a.table[0][noOfOps],a.final);
    addConn(a.table[a.final-1][noOfOps],1);
    addConn(a.table[a.final-1][noOfOps],a.final);
    return a;
}

op applyConc(op a, op b)
{
    addConn(a.table[a.final][noOfOps], a.final+1);
    a=copyAfter(a, b);
    return a;
}

op applyAlter(op a, op b)
{
    a=moveConns(a);
    addConn(a.table[0][noOfOps], 1);
    addConn(a.table[0][noOfOps], a.final+1);
    addConn(a.table[a.final][noOfOps], a.final+b.final+2);
    a=copyAfter(a, b);
    addConn(a.table[a.final][noOfOps], a.final+1);
    a.final+=1;
    return a;
}

int isOp(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void printOp(op a)
{
    cout<<"\t";
    for(int i=0;i<noOfOps;i++)
    {
        cout<<char('a'+i)<<"\t";
    }
    cout<<"E\t\n";

    for(int i=0;i<=a.final;i++)
    {
        cout<<i;
        for(int j=0;j<noOfOps+1;j++)
        {
            cout<<"\t"<<a.table[i][j];
        }
        cout<<endl;
    }
}

op createOp(char a)
{
    op o;
    o.table[0][int(a-'a')]=1;
    for(int i=0;i<noOfOps+1;i++)
        if(i!=int(a-'a'))
            o.table[0][i]=-1;
    for(int i=1;i<noOfStates;i++)
        for(int j=0;j<noOfOps+1;j++)
            o.table[i][j]=-1;
    o.final=1;
    return o;
}

int main()
{
    char exp[20];
    op a,b;
    cout<<"Enter yer expression";
    cin>>exp;
    strcpy(exp, inToPost(exp));
    cout<<exp<<endl;
    StackOp* stackOp = createStackOp(strlen(exp));
    for(int i=0;exp[i]!='\0';i++)
    {
        if(isOp(exp[i]))
        {
            a=createOp(exp[i]);
            pushOp(stackOp, a);
        }
        else if(exp[i]=='*')
        {
            a=popOp(stackOp);
            a=applyKleene(a);
            pushOp(stackOp,a);
        }
        else if(exp[i]=='+')
        {
            b=popOp(stackOp);
            a=popOp(stackOp);
            a=applyConc(a, b);
            pushOp(stackOp,a);
        }
        else if(exp[i]=='.')
        {
            b=popOp(stackOp);
            a=popOp(stackOp);
            a=applyAlter(a, b);
            pushOp(stackOp,a);
        }
    }
    a=popOp(stackOp);
    printOp(a);
    return 0;
}
