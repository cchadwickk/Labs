#include<iostream>
#include<ctype.h>
#include<cstring>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<iomanip>

using namespace std;

string gram[10];
string firsts[10];
vector<int> firstProds[10];
string follows[10];
vector<int> followProds[10];
string nonTerm;
string term;
int table[10][10];
int gCnt=-1,fCnt=0,foCnt=0;

void addVar(char toAdd, char addTo, int prodNo){
    char retVal;
    char str[10];
    int pos;

    for(pos=0;pos<fCnt;pos++)
        if(firsts[pos][0]==addTo)
            break;


    if(pos==fCnt)     //If first variable to add.
    {
        sprintf(str,"%c%c",addTo,toAdd);
        firsts[pos]=str;
        firstProds[pos].push_back(0);
        firstProds[pos].push_back(prodNo);
        fCnt++;
        return;
    }

    retVal = firsts[pos].find_first_of(toAdd);     //Check if toAdd is already present.

    if(retVal==string::npos)             //Add if not already present.
    {
        sprintf(str,"%c",toAdd);
        firsts[pos].append(str);
        firstProds[pos].push_back(prodNo);
    }
}

void addVars(const char* toAdd, char addTo, int prodNo)
{
    for(int i=0;toAdd[i]!='\0';i++)             //Individually add every element.
    {
        if(toAdd[i]!='e')
            addVar(toAdd[i],addTo,prodNo);
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

    for(int i=0;i<gCnt;i++)
    {
        if(gram[i][0]!=x)
            continue;
        int j=2;
        if(gram[i][j]=='e')
        {
            while(gram[i][j]=='e')
                j++;
            if(gram[i][j]=='\0')
            {
                addVar('e', gram[i][0], i);
                continue;
            }
        }

        if(isupper(gram[i][j]))         //If the first element of production is a non-terminal
        {
            flag=1;
            while((isupper(gram[i][j]))&&(gram[i][j]!='\0')&&flag)
            {                           //While non-terminators come and contain empty production(s)
                flag=0;
                retVal = first(gram[i][j]);

                for(int k=0;retVal[k]!='\0';k++)        //Check if empty production is present
                    if(retVal[k]=='e')
                        flag=1;

                addVars(&retVal[0], gram[i][0], i);
                j++;
            }

            if((gram[i][j]!='\0')&&(islower(gram[i][j]))&&flag)
                addVar(gram[i][j], gram[i][0], i);  //If terminal after empty non terminals

            else if(flag==1)                         //If all empty non terminals in current production
                addVar('e', gram[i][0], i);
        }
        else                           //If the first element of production is a terminal
            addVar(gram[i][j], gram[i][0], i);
    }
    for(int i=0;i<fCnt;i++)
        if(firsts[i][0]==x)
            return &firsts[i][1];
}

void addVarFollow(const char toAdd, char addTo, int prodNo)
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
        sprintf(str,"%c%c",addTo,toAdd);
        follows[foCnt]=str;
        followProds[foCnt].push_back(0);
        followProds[foCnt].push_back(prodNo);
        foCnt++;
        return;
    }

    retVal = follows[i].find_first_of(toAdd);     //Check if toAdd is already present.

    if(retVal==string::npos)             //Add if not already present.
    {
        sprintf(str,"%c",toAdd);
        follows[i].append(str);
        followProds[i].push_back(prodNo);
    }
}

void addVarsFollow(const char* toAdd, char addTo, int prodNo)
{
    for(int i=0;toAdd[i]!='\0';i++)             //Individually add every element.
    {
        if(toAdd[i]!='e')
            addVarFollow(toAdd[i],addTo,prodNo);
    }
}

string follow(char x)
{
    int flag;
    string retVal;
    if(x==gram[0][0])
        addVarFollow('$', x, 0);

    for(int i=0;i<gCnt;i++)
    {
        for(int j=2; gram[i][j]!='\0'; j++)
        {
            if(gram[i][j]==x)
            {
                if(gram[i][j+1]=='\0')
                    addVarsFollow(follow(gram[i][0]).c_str(), x, i);
                else
                {
                    flag=1;
                    j++;
                    while((gram[i][j]!='\0')&&flag)
                    {
                        flag=0;
                        retVal = first(gram[i][j]);

                        for(int k=0;retVal[k]!='\0';k++)
                            if(retVal[k]=='e')
                                flag=1;

                        addVarsFollow(retVal.c_str(), x, i);
                        j++;
                    }

                    retVal = follow(gram[i][0]);

                    if(flag)
                        addVarsFollow(retVal.c_str(), gram[i][0], i);
                }
            }
        }
    }

    for(int i=0;i<foCnt;i++)
        if(follows[i][0]==x)
            return &follows[i][1];
}

void insertProd(char NonT, int pos, string prod)
{
    for(int i=gCnt;i>pos;i--)
    {
        gram[i]=gram[i-1];
    }
    gram[pos]=NonT;
    gram[pos].append("=");
    gram[pos].append(prod);
    gCnt++;
}

void changeProds()
{
    int pos,pos2;
    for(int i=0;i<gCnt;i++)
    {
        pos=-2;
        while(pos!=string::npos)
        {
            pos=gram[i].find_first_of('|');
            if(pos==string::npos)
                break;
            else
            {
                pos2=gram[i].find_first_of('|',pos+1);
                insertProd(gram[i][0], i+1, gram[i].substr(pos+1,pos2-(pos+1)));
                gram[i].erase(pos,string::npos-(pos+1));
            }
        }
    }
}

int reducibleToE(char a)
{
    int j;
    if(a=='e')
        return 1;
    for(int i=0;i<gCnt;i++)
    {
        if(gram[i][0]!=a)
            continue;
        for(j=2;gram[i][j]!='\0';j++)
        {
            if(gram[i][j]=='e')
                continue;
            else if(islower(gram[i][j]))
                break;
            else if(!reducibleToE(gram[i][j]))
                break;
            else
                continue;
        }
        if(gram[i][j]=='\0')
            return 1;
    }
    return 0;
}

void formTable()
{
    char temp[3];
    int pos;
    for(int i=0;i<fCnt;i++)
        nonTerm.push_back(firsts[i][0]);

    for(int i=0;i<fCnt;i++)
        for(int j=1;firsts[i][j]!='\0';j++)
            if(term.find_first_of(firsts[i][j])==string::npos)
                term.push_back(firsts[i][j]);

    for(int i=0;i<foCnt;i++)
        for(int j=1;follows[i][j]!='\0';j++)
            if(term.find_first_of(follows[i][j])==string::npos)
                term.push_back(follows[i][j]);

    for(int i=0;i<fCnt;i++)
    {
        for(int j=1;firsts[i][j]!='\0';j++)
        {
            pos=term.find_first_of(firsts[i][j]);
            table[i][pos]=firstProds[i][j];
        }
        if(reducibleToE(firsts[i][0]))
        {
            int k;
            for(k=0;(follows[k][0]!=firsts[i][0]&&k<foCnt);k++);
            for(int j=1;follows[k][j]!='\0';j++)
            {
                pos=term.find_first_of(follows[k][j]);
                table[i][pos]=followProds[k][j];
            }
        }
    }

}

void printTable()
{
    const char separator    = ' ';
    const int width     = 2;
    cout<<"\n\n  ";
    for(int i=0;term[i]!='\0';i++)
    {
        cout<< right << setw(width) << setfill(separator)<<term[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<nonTerm[i]!='\0';i++)
    {
        cout<<nonTerm[i]<<" ";
        for(int j=0;term[j]!='\0';j++)
        {
            if(table[i][j]!=-1)
                cout<< right << setw(width) << setfill(separator)<<table[i][j]<<" ";
            else
                cout<< right << setw(width) << setfill(separator)<<"."<<" ";
        }
        cout<<endl;
    }
}

main()
{
    fill_n(table[0], 100, -1);
    cout<<"Enter no of lines of grammer\n";
    cin>>gCnt;
    cout<<"Enter grammer A=B|c format:\n";
    for(int i=0;i<gCnt;i++)
        cin>>gram[i];
    changeProds();

    cout<<endl;
    for(int i=0;i<gCnt;i++)
        cout<<i<<": "<<gram[i]<<endl;

    for(int i=0;i<gCnt;i++){
        first(gram[i][0]);
    }
    for(int i=0;i<gCnt;i++){
        follow(gram[i][0]);
    }

    formTable();

    cout<<"\nFIRSTS:\n";
    for(int i=0;i<fCnt;i++){
        cout<<"\n["<<firsts[i][0]<<"]->{"<<&firsts[i][1]<<"}"<<endl<<"Prod: ";
        for(int j=1;j<firstProds[i].size();j++)
            cout<<firstProds[i][j];
    }

    cout<<"\n\nFOLLOWS:\n";
    for(int i=0;i<foCnt;i++){
        cout<<"\n["<<follows[i][0]<<"]->{"<<&follows[i][1]<<"}"<<endl<<"Prod: ";
        for(int j=1;j<followProds[i].size();j++)
            cout<<followProds[i][j];
    }

    printTable();

    return 0;
}
