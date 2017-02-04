#include<fstream>
#include<iostream>
#include<stdio.h>
using namespace std;
main()
{
    char ch,ofname[15];
    cout<<"Enter file name";
    cin>>ofname;
    ifstream ifile(ofname);
    ofstream ofile("temp.txt");

    while(1){
        ifile.get(ch);
        if(ifile.eof())
            break;

        switch(ch)
        {
            case '"':
                do{
                    ofile.put(ch);
                    ifile.get(ch);
                }while(ch!='"');
                ofile.put(ch);
                break;

            case '/':
                ifile.get(ch);
                if(ch=='/')
                {
                    while(ch!='\n')ifile.get(ch);
                }
                else if(ch=='*')
                {
                    while(!ifile.eof())
                    {
                        ifile.get(ch);
                        if(ch=='*')
                        {
                            ifile.get(ch);
                            if(ch=='/')
                                break;
                        }
                    }
                }
                else
                {
                    ofile.put('/');
                    ofile.put(ch);
                }
                break;

            default:
                ofile.put(ch);
        }
    }
    ofile.close();
    ifile.close();
    rename(ofname,"backup.txt");
    rename("temp.txt",ofname);

    return 0;
}
