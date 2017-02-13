#include<iostream>
#include"../comment/comment.h"
#include"../keyword/keyword.h"
using namespace std;

void commentPart(char name[15])
{
    int commCnt=0;
    charFileManager comnt;
    comnt.openfiles(name, "temp.txt");
    while(comnt.read(0)>=0)
    {
        switch(comnt.c())
        {
            case '"':
                comnt.write();
                do{
                    comnt.read(1);
                }while(comnt.c()!='"');
                break;

            case '/':
                if(comnt.read(0)=='/')
                {
                    commCnt++;
                    cout<<"Comment removed at: "<<comnt.retLineCnt()<<endl;
                    while(comnt.read(0)!='\n');
                }
                else if(comnt.c()=='*')
                {
                    commCnt++;
                    cout<<"Comment removed at: "<<comnt.retLineCnt()<<endl;
                    while(comnt.read(0))
                        if(comnt.c()=='*')
                            if(comnt.read(0)=='/')
                                break;
                }
                else
                {
                    comnt.write('/');
                    comnt.write();
                }
                break;

            default:
                comnt.write();
        }
    }
    cout<<commCnt<<" comment(s) removed successfully.\n";
    comnt.closefiles();
}
void keywordPart(char name[15], char keyfile[15])
{
    keyword k;
    k.loadKeyFile(keyfile);
    k.openfile(name);
    cout<<"Keywords found :\n";
    while(k.read()>=0)
    {
        if(k.c()=='"')
        {
            k.addChar('\0');
            if(k.findMatch())
            {
                k.printCurr();
                cout<<endl;
            }
            k.resetStrCnt();
            while(k.read()!='"');
        }
        else if(k.splCheck())
        {
            k.addChar('\0');
            if(k.findMatch())
            {
                k.printCurr();
                cout<<endl;
            }
            k.resetStrCnt();
        }
        else
        {
            k.addChar();
        }
    }
    k.closefile();
}

class identifier:public keyword{
public:
    int checkValid()
    {
        int i=1;
        if(currString[0]=='*'){                 //FOR POINTERS
            for(;i<strcnt&&currString[i]!='\0'&&currString[i]=='*';i++);     //CHECK FOR MULTIPLE POINTERS
                    if(!( (currString[i]<='z' && currString[i]>='a') || (currString[i]<='Z' && currString[i]>='A') || currString[i]=='_'))
                        return 0;
            return 1;
        }
        else
        {
            if(!( (currString[0]<='z' && currString[0]>='a') || (currString[0]<='Z' && currString[0]>='A') || currString[0]=='_'))
                return 0;
        }
        for(;i<strcnt&&currString[i]!='\0';i++)
            if(!( (currString[i]<='z' && currString[i]>='a') || (currString[i]<='Z' && currString[i]>='A') || currString[0]=='_' || (currString[i]<='9'&&currString[i]>='0')))
                return 0;
        return 1;
    }
    int checkInvalid()
    {
        if(currString[0]<='9'&&currString[0]>='0')
            for(int i=0;i<strcnt&&currString[i]!='\0';i++)
                if(!(currString[i]<='9'&&currString[i]>='0'))
                    return 1;
        return 0;
    }
};

void identifierPart(char name[15], char keyfile[15])
{
    identifier i;
    i.loadKeyFile(keyfile);
    i.openfile(name);
    cout<<"Identifiers found :\n";
    while(i.read()>=0)
    {
        if(i.c()=='"')
        {
            i.addChar('\0');
            if(!i.findMatch())
            {
                if(i.checkValid()){
                    i.printCurr();
                    cout<<"\n";
                }

                else if(i.checkInvalid())
                {
                    cout<<"Invalid identifier ";
                    i.printCurr();
                    cout<<" ";
                    i.printLine();
                    cout<<"\n";
                }
            }
            i.resetStrCnt();
            while(i.read()!='"');
        }
        else if(i.splCheck())
        {
            i.addChar('\0');
            if(i.checkValid())
            {
                if(!i.findMatch())
                {
                    i.printCurr();
                    cout<<"\n";
                }
            }
            else if(i.checkInvalid())
            {
                cout<<"Invalid identifier ";
                i.printCurr();
                cout<<" ";
                i.printLine();
                cout<<"\n";
            }
            i.resetStrCnt();
        }
        else
        {
            i.addChar();
        }
    }
    i.closefile();
}
int main()
{
    char name[15],keyfile[15];
    cout<<"Enter file name\n";
    cin>>name;
    commentPart(name);
    cout<<"Enter key file\n";
    cin>>keyfile;
    keywordPart(name,keyfile);
    identifierPart(name,keyfile);
    return 0;
}
