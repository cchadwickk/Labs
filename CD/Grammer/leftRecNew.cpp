#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findlen(string inp)
{
    int pos;
    pos = inp.find_first_of("|");
    if(pos==string::npos)
        pos=inp.size();
    return pos;
}
main()
{
    string inp,out1,out2;
    int pos,flag=0;
    char ch;

    cout<<"Enter string (= for ->):\n";
    cin>>inp;

    ch=inp[0];
    out1 = inp;
    out2 = "Z=";
    out1.erase(out1.begin()+2, out1.end());
    inp.erase(inp.begin(), inp.begin() + 2);

    while(inp.length()>0)
    {
        pos = findlen(inp);
        if(inp.at(0)==ch)
        {
            flag=1;
            out2.append(inp.begin() + 1, inp.begin() + pos);
            out2 += "Z|";
        }

        else
        {
            out1.append(inp.begin(), inp.begin() + pos);
            out1 += "Z|";
        }
        inp.erase(0, pos+1);
    }
    out1.erase(out1.end() - 1);
    out2 += "e";

    if(!flag)
        cout<<"No recursion found";
    else
        cout<<out1<<endl<<out2<<endl;

    return 0;

}
