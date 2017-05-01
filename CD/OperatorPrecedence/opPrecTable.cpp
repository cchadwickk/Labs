//no production has 2 consecutive terminals
#include<iostream>
#include<vector>
#include<ctype.h>
using namespace std;
vector<string> gram;
vector<string> leading;
vector<string> trailing;
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

void add(vector<string> &data,char lhs, string toAdd)
{                                           //ADD NEW DATA TO LEADING/TRAILING
    for(int i=0;i<data.size();i++)           //CHECK IF ENTRY ALREADY EXISTS
    {
        if(data[i][0]==lhs)
        {
            for(int j=0;j<toAdd.size();j++)
                if(data[i].find_first_of(toAdd[j])==string::npos)
                    data[i].push_back(toAdd[j]);
            return;
        }
    }
    string str;                             //ELSE ADD NEW ENTRY
    str+=lhs;
    str+=toAdd;
    data.push_back(str);
}

string ret(vector<string> &data,char a)     //RETURN TRAILING/LEADING FOR char a
{
    for(int i=0;i<data.size();i++)           //CHECK IF ALREADY FOUND
        if(data[i][0]==a)
            return data[i].substr(1);
    return "";                              //ELSE RETURN EMPTY
}

string findLeading(char a)
{
    string temp;
    if(ret(leading,a)!="")                   //CHECK IF ALREADY FOUND
        return ret(leading, a);

    for(int i=0;i<gram.size();i++)              //FOR EACH PRODUCTION FOR char a
    {
        if(gram[i][0]==a)                       //IF FIRST CHAR(L.H.S) OF PRODUCTION MATCHES
        {
            for(int j=2;j<gram[i].size();j++)   //GO THROUGH R.H.S
            {
                if(isupper(gram[i][j]))         //IF NON TERMINAL
                {
                    if(gram[i][j]==a)           //IF SAME AS L.H.S
                        continue;
                    add(leading,a,findLeading(gram[i][j]));
                }
                else                            //IF TERMINAL
                {
                    temp=gram[i][j];
                    add(leading,a,temp);        //ADD TO LEADING VECTOR AND EXIT
                    break;
                }
            }
        }
    }
    return ret(leading,a);                      //RETURN FINAL LEADING
}

string findTrailing(char a)
{
    string temp;
    if(ret(trailing,a)!="")                   //CHECK IF ALREADY FOUND
        return ret(trailing,a);

    for(int i=0;i<gram.size();i++)              //FOR EACH PRODUCTION FOR char a
    {
        if(gram[i][0]==a)                       //IF FIRST CHAR(L.H.S) OF PRODUCTION MATCHES
        {
            for(int j=gram[i].size()-1;j>=2;j--)   //GO THROUGH R.H.S
            {
                if(isupper(gram[i][j]))
                {
                    if(gram[i][j]==a)
                        continue;
                    add(trailing,a,findTrailing(gram[i][j]));
                }
                else
                {
                    temp=gram[i][j];
                    add(trailing,a,temp);
                    break;
                }
            }
        }
    }
    return ret(trailing,a);
}
void addInTable(char a, char b, char c) //LIKE ABC WHERE B:"=,<,>"
{
    int flag,flag2;
    string str;
    flag=flag2=-1;
    if(table.size()==0)
    {
        str=" ";
        str+=c;
        table.push_back(str);
        str = a;
        str+= b;
        table.push_back(str);
        return;
    }
    for(int i=0;i<table.size();i++)
    {
        if(table[i][0]==a){
            flag = i;
            break;
        }
    }
    for(int j=0;j<table[0].size();j++)
    {
        if(table[0][j]==c){
            flag2 = j;
            break;
        }
    }
    if(flag == -1)
    {
        str = a;
        table.push_back(str);
        flag = table.size()-1;
        for(int i=1;i<table[0].size();i++)
        {
            table[flag].append(".");
        }
    }
    if(flag2 == -1)
    {
        str = c;
        table[0].append(str);
        flag2 = table[0].size()-1;
        for(int i=1;i<table.size();i++)
        {
            table[i].append(".");
        }
    }
    table[flag][flag2]=b;
}

int samePrec(char a, char b)
{
    char aInd,bInd;
    aInd=bInd=-1;
    for(int i=0;i<gram.size();i++)
    {
        for(int j=2;j<gram[i].size();j++)
        {
            if(gram[i][j]==a)
                aInd = gram[i][0];
            if(gram[i][j]==b)
                bInd = gram[i][0];
            if((bInd>-1)&&(aInd>-1))
                break;
        }
        if((bInd>-1)&&(aInd>-1))
                break;
    }
    if(aInd==bInd)
        return 1;
    else
        return 0;
}
void calcTable()
{
    string str;
    for(int i=0;i<gram.size();i++)
    {
        for(int j=2;j<gram[i].size()-1;j++)
        {
            if(isupper(gram[i][j+1])&&!isupper(gram[i][j]))
            {
                str = findLeading(gram[i][j+1]);
                for(int k=0;k<str.size();k++)
                {
                    addInTable(gram[i][j],'<',str[k]);
                    if((str[k]!=gram[i][j])&&(!samePrec(str[k],gram[i][j])))
                        addInTable(str[k],'>',gram[i][j]);
                }
            }
            if(isupper(gram[i][j])&&!isupper(gram[i][j+1]))
            {
                str = findTrailing(gram[i][j]);
                for(int k=0;k<str.size();k++)
                {
                    addInTable(gram[i][j+1],'>',str[k]);
                    if((str[k]!=gram[i][j+1])&&(!samePrec(str[k],gram[i][j+1])))
                        addInTable(str[k],'<',gram[i][j+1]);
                }
            }
            if(!isupper(gram[i][j+1])&&!isupper(gram[i][j]))
            {
                addInTable(gram[i][j],'=',gram[i][j+1]);
            }
        }
        for(int j=2;j<gram[i].size()-2;j++)
        {
            if(!isupper(gram[i][j])&&isupper(gram[i][j+1])&&!isupper(gram[i][j+2]))
                addInTable(gram[i][j],'=',gram[i][j+2]);
        }
    }

    for(int i=0;i<gram.size();i++)
    {
        str = findTrailing(gram[i][0]);
        for(int j=0;j<str.size();j++)
            addInTable(str[j],'>','$');
    }
    for(int i=0;i<table[0].size();i++)
    {
        str = findLeading(gram[i][0]);
        for(int j=0;j<str.size();j++)
            addInTable('$','<',str[j]);
    }
}

void insertProd(char NonT, int pos, string prod)
{
    string str;
    str=NonT;
    str+="=";
    str+=prod;
    gram.push_back(str);
}

void changeProds()
{
    int pos,pos2;
    for(int i=0;i<gram.size();i++)
    {
        pos=gram[i].find_first_of('|');
        while(pos<gram[i].size())
        {
            pos2=gram[i].find_first_of('|',pos+1);
            insertProd(gram[i][0], i+1, gram[i].substr(pos+1,pos2-(pos+1)));
            gram[i].erase(pos,pos2-pos);
        }
    }
}

main()
{
   /* gram.push_back("S=E");
    gram.push_back("E=E*T|T");
    gram.push_back("T=T+F|F");
    gram.push_back("F=i|(E)");*/

    gram.push_back("S=A");
    gram.push_back("A=T|A+T|A-T");
    gram.push_back("T=F|T*T|T/F");
    gram.push_back("F=P|P^F");
    gram.push_back("P=i|n|(A)");

    changeProds();

    for(int i=0;i<gram.size();i++)
        cout<<gram[i]<<endl;

    for(int i=0;i<gram.size();i++)
    {
        findLeading(gram[i][0]);
        findTrailing(gram[i][0]);
    }

    cout<<"\nLeadings\n";
    for(int i=0;i<leading.size();i++)
    {
        cout<<gram[i][0]<<"->"<<findLeading(gram[i][0])<<endl;
    }
    cout<<"\nTrailings\n";
    for(int i=0;i<trailing.size();i++)
    {
        cout<<gram[i][0]<<"->"<<findTrailing(gram[i][0])<<endl;
    }
    calcTable();

    cout<<"\n";
    printTable();
    return 0;
}
