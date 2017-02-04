#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include"comment.h"
using namespace std;

int main()
{
    char name[15];
    int commCnt=0;
    charFileManager comnt;
    cout<<"Enter file name";
    cin>>name;
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
                    while(comnt.read(0)!='\n');
                }
                else if(comnt.c()=='*')
                {
                    commCnt++;
                    while(comnt.read(0))
                        if(comnt.c()=='*')
                        {
                            if(comnt.read(0)=='/')
                            {
                                break;
                            }
                        }
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
    return 0;
}
