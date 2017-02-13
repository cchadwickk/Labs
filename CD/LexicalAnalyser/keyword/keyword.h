#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class keyword{
protected:
    char keys[90][18], currString[20],ch;
    char specialChars[25];
    int keycnt, strcnt, line;
    ifstream ifile;
public:
    keyword(){
        keycnt=0;
        strcnt=0;
        line=0;
        strcpy(specialChars,"(),[]\n#<>+/- .;\t{}=<>!:\0");
    }

    void openfile(char in[])        //open input file
    {
        ifile.open(in);
        if(!ifile.good()){
            cout<<"Error opening input file";
            exit(1);
        }
    }
    void closefile()                //close input file
    {
        ifile.close();
    }
    char read()                     //read and return character, return -1 on eof
    {
        ifile.get(ch);
        if(ifile.eof())
            return -1;
        if(ch=='\n')
            line++;
        return ch;
    }
    void loadKeyFile(char str[]){   //read keyword file(str[]) and store in keys[]
        ifstream keyFile;
        keyFile.open(str);
        while(!keyFile.eof())
            keyFile.getline(keys[keycnt++],80);
        keyFile.close();
    }
    int findMatch(){                //use binsrch to match currString to one of keys[]
        if(strcnt<=2)
            return 0;
        int frnt=0,bck=keycnt-1,midl,compval;
        while(frnt<=bck)
        {
            midl = (frnt+bck)/2;
            compval = strcmp(keys[midl],currString);
            if(compval==0)
                return 1;
            else if(compval<0)
                frnt=midl+1;
            else
                bck=midl-1;
        }
        return 0;
    }
    void addChar()                      //add character to currString
    {
        currString[strcnt++]=ch;
    }
    void addChar(char toAdd)           //add character to currString
    {
        currString[strcnt++]=toAdd;
    }
    int splCheck()                     //check if special character
    {
        for(int i=0;specialChars[i]!='\0';i++)
            if(specialChars[i]==ch)
                return 1;
        return 0;
    }
    void printCurr()                   //print current string
    {
        if((currString[0]!='\0')&&(strcnt!=0))
            cout<<currString;
    }
    void printLine()
    {
        cout<<"Line: "<<line;
    }
    void resetStrCnt()                  //empty currString
    {
        strcnt=0;
    }
    int retStrCnt()
    {
        return strcnt;
    }
    char c()                            //return currently read char
    {
        return ch;
    }
};
