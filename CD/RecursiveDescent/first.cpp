#include<iostream>
#include<stdlib.h>
using namespace std;
char str[20];
//expr → term { add-op term }
//term → factor { mult-op factor }
//factor → ( expr ) | number
//add-op → + | -
//mult-op → * | / | %
//number → 0 | nz-digit { 0 | nz-digit }
//nz-digit → 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

int factor(char *str,char **retToParent);
int addop(char *str, char **retToParent)
{
    char *retStr;
    cout<<"addop\t"<<str<<endl;
    if(str[0]=='+')
    {
        str++;
        *retToParent = str;
        return 1;
    }
    else if(str[0]=='-')
    {
        str++;
        *retToParent = str;
        return 1;
    }
    else
        return 0;
}

int multop(char *str, char **retToParent)
{
    char *retStr;
    cout<<"multop\t"<<str<<endl;
    if(str[0]=='*')
    {
        str++;
        *retToParent = str;
        return 1;
    }
    else if(str[0]=='/')
    {
        str++;
        *retToParent = str;
        return 1;
    }
    else if(str[0]=='%')
    {
        str++;
        *retToParent = str;
        return 1;
    }
    else
        return 0;
}

int nzdigit(char *str, char **retToParent)
{
    char *retStr;
    cout<<"nzdigit\t"<<str<<endl;
    char temp[3];
    for(int i=1;i<=9;i++)
    {
        itoa(i,temp,10);
        if(str[0]==temp[0])
        {
            str++;
            *retToParent = str;
            return 1;
        }
    }
    return 0;
}

int number(char *str, char **retToParent)
{
    char *retStr;
    cout<<"number\t"<<str<<endl;
    if(str[0]=='0')
    {
        str++;
        *retToParent = str;
        return 1;
    }
    else if(nzdigit(str,&retStr))
    {
        *retToParent = retStr;
        if(number(retStr, &retStr))
        {
            *retToParent = retStr;
            return 1;
        }
        return 1;
    }
    else
        return 0;
}

int term(char *str, char **retToParent)
{
    char *retStr;
    cout<<"term\t"<<str<<endl;
    if(factor(str, &retStr))
    {
        *retToParent = retStr;
        if(multop(retStr, &retStr))
        {
            if(factor(retStr, &retStr))
            {
                *retToParent = retStr;
                return 1;
            }
            return 0;
        }
        else
            return 1;
    }
    return 0;
}

int expr(char *str,char **retToParent)
{
    char *retStr;
    cout<<"expr\t"<<str<<endl;
    if(term(str, &retStr))
    {
        *retToParent = retStr;
        if(addop(retStr, &retStr))
        {
            if(term(retStr, &retStr))
            {
                *retToParent = retStr;
                return 1;
            }
            return 0;
        }
        else
            return 1;
    }
    return 0;
}

int factor(char *str, char **retToParent)
{
    char *retStr;
    cout<<"factor\t"<<str<<endl;
    if(str[0]=='(')
    {
        str++;
        if(expr(str,&retStr))
        {
            if(retStr[0]==')')
            {
                retStr++;
                *retToParent = retStr;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    else if(number(str, &retStr))
    {
        *retToParent = retStr;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *retStr;
    cout<<"Enter input string\n";
    cin>>str;
    if(expr(str, &retStr))
        cout<<"ACCEPTED\n";
    else
        cout<<"FAILED\n";
    return 0;
}
