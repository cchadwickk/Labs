#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<vector>
#include<iomanip>
#include"stackPrint.h"
using namespace std;
vector<string> gram;
int matchWithGram(string str)
{
    for(int i=0;i<gram.size();i++)
    {
        if(gram[i].substr(2)==str)
            return i+1;
    }
    return 0;
}
int bottomUp(string inStr)
{
    stack<char> myStack;
    string str;
    int retval,flag;
    myStack.push('$');
    cout<<left<<setw(15)<<"Input String"<<left<<setw(15)<<"Stack"<<endl<<endl;
    while(1)
    {
        cout<<left<<setw(15)<<inStr<<myStack<<endl<<endl;
        if(inStr.front()=='$')                           //IF INPUT STRING IS EMPTY
            if((myStack.size()==2)&&(myStack.top()=='E')) //IF ONLY "$E" IN STACK
                return 1;

        if(islower(myStack.top()))                      //IF TOPMOST ELEMENT IN STACK IS <id>
        {
            myStack.pop();
            myStack.push('F');
            continue;
        }

        flag=0;
        string str="";
        string temp="";

        while(myStack.top()!='$')                       //FIND IF ANY HANDLE PRESENT
        {
            temp="";
            temp +=myStack.top();
            str.insert(0,temp);
            myStack.pop();
        }
        while(str.size()>0)
        {
            if(retval=matchWithGram(str))
            {
                flag=1;
                retval--;
                break;
            }
            myStack.push(str[0]);
            str.erase(0,1);
        }
        if(flag==1)                                     //PUSH L.H.S. IF HANDLE REMOVED
        {
            myStack.push(gram[retval][0]);
            continue;
        }

        if((inStr.front()=='$') && (flag==0) )          //IF INPUT EMPTY AND NO HANDLE FOUND
        {
            return 0;
        }

        myStack.push(inStr[0]);
        inStr.erase(0,1);
    }
    return 0;
}
main()
{
    gram.push_back("E=E+E");
    gram.push_back("E=F");
    gram.push_back("E=E*E");
    gram.push_back("E=(E)");
    string inStr;
    cout<<"Enter string";
    cin>>inStr;
    inStr.push_back('$');
    if(bottomUp(inStr))
        cout<<"Accepted";
    else
        cout<<"Not accepted";
    return 0;
}
