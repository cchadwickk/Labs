#include<iostream>
#include"../comment/comment.h"
#include"../keyword/keyword.h"
using namespace std;

void commentPart(char name[15]){
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

void keywordPart(char name[15], char keyfile[15]){
    keyword k;
    k.loadKeyFile(keyfile);
    k.openfile(name);
    cout<<"\nKEYWORDS :\n\n";
    while(k.read()>=0)
    {
        if(k.splCheck() || k.c()=='"')
        {
            k.addChar('\0');
            if(k.findMatch())
            {
                k.printCurr();
                cout<<endl;
            }
            k.resetStrCnt();

            if(k.c() == '"')
                while(k.read()!='"');
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
        int i=0;
        if(currString[0]=='*'){                 //FOR POINTERS, SHIFTS CHECK COUNTER TO FIRST NON * CHAR
            for(;i<strcnt&&currString[i]!='\0'&&currString[i]=='*';i++);
        }

        if(!( (currString[i]<='z' && currString[i]>='a') || (currString[i]<='Z' && currString[i]>='A') || currString[i]=='_'))//CHECK FIRST CHARACTER
                return 0;

        for(;i<strcnt&&currString[i]!='\0';i++) //CHECK REMAINING CHARACTERS
            if(!( (currString[i]<='z' && currString[i]>='a') || (currString[i]<='Z' && currString[i]>='A') || currString[0]=='_' || (currString[i]<='9'&&currString[i]>='0')))
                return 0;
        return 1;
    }
    int checkInvalid()
    {
        int i;
        if(currString[0]=='*'){                 //FOR POINTERS
            for(;i<strcnt&&currString[i]!='\0'&&currString[i]=='*';i++);     //INCREASE I TILL FIRST CHAR IN POINTERS
            if(!( (currString[i]<='z' && currString[i]>='a') || (currString[i]<='Z' && currString[i]>='A') || currString[i]=='_'))
                return 1;
        }

        if(currString[0]<='9'&&currString[0]>='0')      //CHECK CONSTANT NUMBERS
            for(i=0;i<strcnt&&currString[i]!='\0';i++)
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
    cout<<"\nIDENTIFIERS :\n\n";

    while(i.read()>=0)
    {
        if(i.splCheck() || i.c()=='"')
        {
            i.addChar('\0');
            if( i.checkValid() && (!i.findMatch()) )    //IF NOT A KEYWORD AND VALID IDENTIFIER
            {
                    i.printCurr();
                    cout<<"\n";
            }

            else if(i.checkInvalid())           //CHECK IF NOT A CONSTANT OR SPACE
            {
                cout<<"\tError ";
                i.printCurr();
                cout<<" at ";
                i.printLine();
                cout<<"\n";
            }

            if(i.c()=='"')
                while(i.read()!='"');
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
