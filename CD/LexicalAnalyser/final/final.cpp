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
                do{
                    comnt.write();
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
        if(k.splCheck())
        {
            k.addChar('\0');
            if(k.findMatch())
            {
                k.printCurr();
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

int main()
{
    char name[15],keyfile[15];
    cout<<"Enter file name\n";
    cin>>name;
    commentPart(name);
    cout<<"Enter key file\n";
    cin>>keyfile;
    keywordPart(name,keyfile);
    return 0;
}
