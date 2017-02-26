#include<iostream>
#include<ctype.h>
#include<string.h>
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
using namespace std;
main()
{
    int oInd=0,dpos,pdpos,val,pInd=0,alreadyE=0;
    char str[20],out[10][20],alpha[20],print[10][20];
    cout<<"Enter string in format A=Aa|b\n";
    cout<<"Where, A and a,b are non terminal and terminals respectively\n";
    cin>>str;

    for( dpos=0; str[dpos]!='|'; dpos++ );
    strcpy(out[oInd], &str[2]);
    out[oInd++][dpos-2]='\0';
    cout<<out[oInd-1]<<endl;
    strcpy(alpha,out[0]);
    while(1)
    {
        pdpos=dpos;
        for( dpos++ ; ((str[dpos]!='|')&&(str[dpos]!='\0')) ; dpos++ );
        if(str[dpos]=='\0')
            break;
        strcpy(out[oInd], &str[pdpos+1]);
        out[oInd][(dpos-pdpos)-1]='\0';
        cout<<out[oInd]<<endl;

        if(strc(alpha,out[oInd]))
        {
            val = fabs( strc( alpha , out[oInd] ) );
            if(val < strlen(alpha))
                alpha[val]='\0';
        }
        oInd++;
    }
    cout<<val<<endl;

    strcpy(print[pInd],str);
    print[pInd][2+val]='\0';
    strcat(print[pInd], "Z");
    strcat(print[pInd], &str[pdpos]);
    print[pInd][strlen(print[pInd])-1]='\0';
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
    return 0;
}
