#include<iostream>
#include<ctype.h>
#include<cstring>
#include<stdio.h>

using namespace std;

string gram[10];
string firsts[10];
string follows[10];
int gCnt=-1,fCnt=0,foCnt=0;

void addVar(string* x, char toAdd, char addTo){
    char retVal;
    char str[10];

    if((*x).length()<1)     //If first variable to add.
    {
        sprintf(str,"%c%c",addTo,toAdd);
        *x = str;
        return;
    }

    retVal = (*x).find_first_of(toAdd);     //Check if toAdd is already present.

    if(retVal==string::npos)             //Add if not already present.
    {
        sprintf(str,"%c",toAdd);
        (*x).append(str);
    }
}

void addVars(string* x,const char* toAdd, char addTo)
{
    for(int i=0;toAdd[i]!='\0';i++)             //Individually add every element.
    {
        if(toAdd[i]!='e')
            addVar(x,toAdd[i],addTo);
    }
}

string first(char x)
{
    string retVal;
    retVal=x;
    char *toAdd;
    int t,i,flag;

    if(islower(x))
        return retVal;

    for(i=0; i<fCnt; i++)   //Find if a first has already been evaluated.
        if(firsts[i][0]==x)
            return &firsts[i][1];

    for(i=0; i<gCnt; i++)   //Find where in the grammer is required production present.
        if(gram[i][0]==x)
            break;

    for(int j=2; gram[i][j]!='\0'; j++)
    {
        if(isupper(gram[i][j]))         //If the first element of production is a non-terminal
        {
            flag=1;
            while((isupper(gram[i][j]))&&(gram[i][j]!='|')&&(gram[i][j]!='\0')&&flag)
            {                           //While non-terminators come and contain empty production(s)
                flag=0;
                retVal = first(gram[i][j]);

                for(int k=0;retVal[k]!='\0';k++)        //Check if empty production is present
                    if(retVal[k]=='e')
                        flag=1;

                addVars(&firsts[fCnt], retVal.c_str(), gram[i][0]);
                j++;
            }

            if((gram[i][j]!='|')&&(gram[i][j]!='\0')&&(islower(gram[i][j]))&&(flag))
                addVar(&firsts[fCnt], gram[i][j], gram[i][0]);  //If terminal after empty non terminals

            else if(flag==1)                                           //If all empty non terminals in current production
                addVar(&firsts[fCnt], 'e', gram[i][0]);
        }

        else                            //If the first element of production is a terminal
            addVar(&firsts[fCnt], gram[i][j], gram[i][0]);

        while((gram[i][j+1]!='\0')&&(gram[i][j]!='|'))  //Skip to next production for same non terminal
            j++;

    }
    return &firsts[fCnt++][1];
}

void addVarFollow(const char toAdd, char addTo)
{
    char retVal;
    char str[10];
    int i;

    for(i=0;i<foCnt;i++)
    {
        if(follows[i][0]==addTo)
            break;
    }

    if(i==foCnt)     //If first variable to add.
    {
        foCnt++;
        sprintf(str,"%c%c",addTo,toAdd);
        follows[foCnt-1]=str;
        return;
    }

    follows[i];

    retVal = follows[i].find_first_of(toAdd);     //Check if toAdd is already present.

    if(retVal==string::npos)             //Add if not already present.
    {
        sprintf(str,"%c",toAdd);
        follows[i].append(str);
    }
}

void addVarsFollow(const char* toAdd, char addTo)
{
    for(int i=0;toAdd[i]!='\0';i++)             //Individually add every element.
    {
        if(toAdd[i]!='e')
            addVarFollow(toAdd[i],addTo);
    }
}

string follow(char x)
{
    int flag;
    string retVal;
    if(x==gram[0][0])
        addVarFollow('$', x);

    for(int i=0;i<gCnt;i++)
    {
        for(int j=2; gram[i][j]!='\0'; j++)
        {
            if(gram[i][j]==x)
            {
                if((gram[i][j+1]=='|')||(gram[i][j+1]=='\0'))
                    addVarsFollow(follow(gram[i][0]).c_str(), x);
                else
                {
                    flag=1;
                    j++;
                    while((gram[i][j]!='|')&&(gram[i][j]!='\0')&&flag)
                    {
                        flag=0;
                        retVal = first(gram[i][j]);

                        for(int k=0;retVal[k]!='\0';k++)
                            if(retVal[k]=='e')
                                flag=1;

                        addVarsFollow(retVal.c_str(), x);
                        j++;
                    }

                    retVal = follow(gram[i][0]);

                    if(flag)
                        addVarsFollow(retVal.c_str(), gram[i][0]);
                }
            }
        }
    }

    for(int i=0;i<foCnt;i++)
        if(follows[i][0]==x)
            return &follows[i][1];
}

main()
{

    cout<<"Enter no of lines of grammer\n";
    cin>>gCnt;
    cout<<"Enter grammer A=B|c format:\n";
    for(int i=0;i<gCnt;i++)
        cin>>gram[i];

    cout<<"FIRSTS:\n";
    for(int i=0;i<gCnt;i++)
        cout<<"["<<gram[i][0]<<"]->{"<<first(gram[i][0])<<"}"<<endl;

    for(int i=0;i<gCnt;i++)
        follow(gram[i][0]);

    cout<<"FOLLOWS:\n";
    for(int i=0;i<foCnt;i++)
        cout<<"["<<follows[i][0]<<"]->{"<<&follows[i][1]<<"}"<<endl;

    return 0;
}
