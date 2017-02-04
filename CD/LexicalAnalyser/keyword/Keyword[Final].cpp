#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include"keyword.h"
using namespace std;
int main()
{
    char keyfile[15], name[15];
    cout<<"Enter name of input file";
    cin>>name;
    cout<<"Enter name for keys file.\n";
    cin>>keyfile;
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
    return 0;
}
