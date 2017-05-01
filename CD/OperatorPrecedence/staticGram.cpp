#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<vector>
#include<iomanip>
#include"stackPrint.h"
using namespace std;
vector<string> table;

void printTable()
{
    for(int i=0;i<table.size();i++)
    {
        for(int j=0;j<table[0].size();j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
}

char retPrec(char a, char b)
{
    int aInd,bInd;
    aInd=bInd=-1;
    for(int i=0;i<table.size();i++)
        if(table[i][0]==a)
            aInd=i;

    for(int i=1;i<table[0].size();i++)
        if(table[0][i]==b)
            bInd=i;
    return table[aInd][bInd];
}

int opPrec(string inStr)
{
    stack<char> myStack;
    string str;
    int retval,flag;
    myStack.push('$');
    cout<<left<<setw(15)<<"InputString"<<left<<setw(10)<<"Prec"<<left<<setw(15)<<"Stack"<<endl<<endl;
    while(1)
    {
        char a = myStack.top();
        char b = inStr[0];

        cout<<left<<setw(15)<<inStr<<left<<setw(10)<<retPrec(a,b)<<myStack<<endl<<endl;
        if(inStr.front()=='$')                           //IF INPUT STRING IS EMPTY
            if((myStack.top()=='$'))                        //IF ONLY "$" IN STACK
                return 1;

        if(retPrec(a,b)=='<')                           //PUSH FIRST CHAR FROM INPUT
        {                                               //AND REMOVE IT FROM INPUT
            myStack.push(inStr[0]);
            inStr.erase(0,1);
            b=inStr[0];
        }
        else if((retPrec(a,b)=='='))
        {
            myStack.pop();
            inStr.erase(0,1);
            b=inStr[0];
            a=myStack.top();
        }
        else if((retPrec(a,b)=='>'))
        {
                myStack.pop();
                a=myStack.top();
        }
        else if((retPrec(a,b)=='.'))
        {
            cout<<"No valid entry in precedence table\n";
            return 0;
        }
        else
        {
            cout<<"Invalid output from retPrec()\n";
        }
    }
    return 0;
}

main()
{
    table.push_back(" $()i^*/+-");
    table.push_back("$.<.<<<<<<<");
    table.push_back("(.<=<<<<<<<");
    table.push_back(")>.>..>>>>>");
    table.push_back("i>.>..>>>>>");
    table.push_back("n>.>..>>>>>");
    table.push_back("^><><<<>.>>");
    table.push_back("*><><<<>>>>");
    table.push_back("/><><<<>>>>");
    table.push_back("+><><<<<<>>");
    table.push_back("-><><<<<<>>");

    printTable();

    string inStr;
    cout<<"Enter string";
    cin>>inStr;
    inStr.push_back('$');
    if(opPrec(inStr))
        cout<<"Accepted";
    else
        cout<<"Not accepted";
    return 0;
}
