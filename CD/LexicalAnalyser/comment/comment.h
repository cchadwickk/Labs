#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class charFileManager{
protected:
    ifstream ifile;
    ofstream ofile;
    char infile[20],oufile[20];
    int line;
    char ch;
public:
    charFileManager(){
        line=1;
    }

    void openfiles(char in[], char out[]){  //(input file, temporary output file)
        strcpy(infile,in);
        strcpy(oufile,out);
        ifile.open(in);
        ofile.open(out);
        if(!ifile.good())
        {
            cout<<"Error opening read file.\n";
            exit(1);
        }
        if(!ofile.good())
        {
            cout<<"Error opening write file.\n";
            exit(1);
        }
    }

    void filechange(){              //rename files, create backup files
        remove("backup.txt");
        if(rename(infile,"backup.txt"))
            cout<<"error renaming file";
        if(rename(oufile,infile))
            cout<<"Error renaming file";
    }

    void closefiles(){          //close files and call filechange()
        ifile.close();
        ofile.close();
        filechange();
    }

    char read(int wryte){       //read character and return(bool value=write to file ?)
        ifile.get(ch);
        if(ch=='\n')
            line++;
        if(wryte)
            ofile.put(ch);
        if(ifile.eof())
            return -1;
        return ch;
    }

    void write(){               //write char to output file
        ofile.put(ch);
    }

    void write(char cha){       //write explicitly sent char(to be written)
        ofile.put(cha);
    }

    char c(){                   //return char read
        return ch;
    }

    int retLineCnt()
    {
        return line;
    }

};
