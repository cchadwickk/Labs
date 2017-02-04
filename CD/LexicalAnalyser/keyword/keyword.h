#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class keyword{
    char keys[90][18], currString[20],ch;
    char specialChars[25];
    int keycnt, strcnt;
    ifstream ifile;
public:
    keyword(){
        keycnt=0;
        strcnt=0;
        strcpy(specialChars,"(),[]\n#<> .;\t{}=<>!:\0");
    }

    void openfile(char in[])        //open input file
    {
        ifile.open(in);
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
        return ch;
    }
    void loadKeyFile(char str[]){   //read keyword file(str[]) and store in keys[]
        ifstream keyFile;
        keyFile.open(str);
        while(!keyFile.eof())
            keyFile.getline(keys[keycnt++],80);
        keyFile.close();
        cout<<keycnt<<" keys loaded successfully\n";
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
            cout<<currString<<endl;
    }
    void resetStrCnt()                  //empty currString
    {
        strcnt=0;
    }
    char c()                            //return currently read char
    {
        return ch;
    }
};
