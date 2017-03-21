#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
int strc(char *a, char *b)
{
    int i;
    for(i=0;a[i]!='\0'&&a[i]!='\0'&&a[i]==b[i];i++);
    return i;
}
int fabs(int a)
{
    if(a<0)
        return -a;
    return a;
}
void leftfact(char str[])
{
    int oInd=0,dpos,pdpos,val,pInd=0,alreadyE=0;
    char out[10][20],alpha[20],print[10][20],eps=141;

    for( dpos=0; str[dpos]!='|'; dpos++ );
    strcpy(out[oInd], &str[2]);
    out[oInd++][dpos-2]='\0';
    strcpy(alpha,out[0]);
    while(1)
    {
        pdpos=dpos;
        for( dpos++ ; ((str[dpos]!='|')&&(str[dpos]!='\0')) ; dpos++ );
        if(str[dpos]=='\0')
            break;
        strcpy(out[oInd], &str[pdpos+1]);
        out[oInd][(dpos-pdpos)-1]='\0';

        if(strc(alpha,out[oInd]))
        {
            val = fabs( strc( alpha , out[oInd] ) );
            if(val < strlen(alpha))
                alpha[val]='\0';
        }
        oInd++;
    }

    strcpy(print[pInd],str);
    print[pInd][2+val]='\0';
    strcat(print[pInd], "Z");
    strcat(print[pInd], &str[pdpos]);
    pInd++;

    strcpy(print[pInd],"Z=");
    for(int i=0; i<oInd; i++)
    {
        if(strlen(out[i])>val)
        {
            strcat(print[pInd], &out[i][val]);
            strcat(print[pInd],"|");
        }
        else if(alreadyE==0)
        {
            alreadyE=1;
            strcat(print[pInd], "e");
            strcat(print[pInd],"|");
        }
    }
    print[pInd][strlen(print[pInd])-1]='\0';

    cout<<print[0]<<"\n"<<print[1];
}
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
    char temp[20];
    int pos,flag=0;
    char ch;

    cout<<"Enter string (= for ->):\n";
    cin>>inp;

    ch=inp[0];
    out1 = inp;
    out2 = "Y=";
    out1.erase(out1.begin()+2, out1.end());
    inp.erase(inp.begin(), inp.begin() + 2);

    while(inp.length()>0)
    {
        pos = findlen(inp);
        if(inp.at(0)==ch)
        {
            flag=1;
            out2.append(inp.begin() + 1, inp.begin() + pos);
            out2 += "Y|";
        }

        else
        {
            out1.append(inp.begin(), inp.begin() + pos);
            out1 += "Y|";
        }
        inp.erase(0, pos+1);
    }
    out1.erase(out1.end() - 1);
    out2 += "e";

    if(!flag){
        cout<<"No recursion found";
        cout<<"After left factoring ?\n";
        strcpy(temp,inp.c_str());
        leftfact(temp);
    }
    else{
        cout<<out1<<endl<<out2<<endl;
        cout<<"After left factoring ?\n";
        strcpy(temp,out2.c_str());
        leftfact(temp);
    }

    return 0;

}
