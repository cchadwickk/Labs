#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<vector>
#include<iomanip>
#include"stackPrint.h"
using namespace std;

struct data{
    char SorR;
    int state;
};

string rowInd;
string colInd;

vector<vector<int>> goTable;
vector<vector<data>> acTable;

main()
{

    printTable();

    gram.push_back("S=A");
    gram.push_back("A=T|A+T|A-T");
    gram.push_back("T=F|T*F|T/F");
    gram.push_back("F=P|P^F");
    gram.push_back("P=i|n|(A)");

    changeProds();

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
