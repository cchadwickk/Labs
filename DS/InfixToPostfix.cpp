#include<iostream>
#include<windows.h>
using namespace std;
class astack{
    char arr[30];
    int top;
public:
    astack()
    {
        top=-1;
    }
    void push(char a);
    char pop();
    int aempty();
    char retstcktop();
};
char astack::retstcktop()
{
    if(!aempty())
        return arr[top];
    else
        return -1;
}
int astack::aempty()
{
    return (top==-1);
}
void astack::push(char a)
{
    if(top<29)
        arr[++top]=a;
    else
    {
        cout<<"ERROR : OVERFLOW OCCURED";
        exit(1);
    }
}
char astack::pop()
{
    if(!aempty())
        return arr[top--];
    else
    {
        cout<<"ERROR : STACK EMPTY";
        exit(1);
    }
}
int priority(char a)
{
    if(a=='(')
        return -2;
    else if((a=='*')||(a=='/'))
        return 2;
    else if((a=='+')||(a=='-'))
        return 1;
    else if(a==')')
        return 0;
    else
        return -1; //INCASE ITS AN OPERAND
}
int main()
{
    char exp[30],result[30],temp;
    int resind=0;   //IT HOLDS THE INDEX WHERE ELEMENT IS TO BE PUT
    astack xyz;
    cout<<"Enter your expression";
    cin>>exp;
    for(int i=0;exp[i]!='\0';i++)
    {
        switch(priority(exp[i]))
        {
        case -2:
            xyz.push(exp[i]);
            break;
        case 0:
            while((temp=xyz.pop())!='(')
                result[resind++]=temp;
            break;
        case -1:
            result[resind++]=exp[i];
            break;
        default:
            if(priority(xyz.retstcktop())<=priority(exp[i]))
                xyz.push(exp[i]);
            else
            {
                while(priority(xyz.retstcktop())>priority(exp[i]))
                {
                    result[resind++]=xyz.pop();
                }
                xyz.push(exp[i]);
            }
        }
    }
    while(!xyz.aempty())
    {
        result[resind++]=xyz.pop();
    }
    result[resind++]='\0';
    cout<<"\n\n\n"<<result;
    return 0;
}
