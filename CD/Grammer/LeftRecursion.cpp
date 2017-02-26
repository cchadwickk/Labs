#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
main()
{
    int oInd=0,dpos;
    char str[20],out[10][20];
    cout<<"Enter string in format A=Aa|b\n";
    cout<<"Where, A and a,b are non terminal and terminals respectively\n";
    cin>>str;

    for( dpos=0; str[dpos]!='|'; dpos++ );         //FIND POSITION OF '|'

    strcpy( out[oInd], str );             //COPY A=

    strcpy( &out[oInd][2], &str[dpos+1] );   //COPY terminal production

    strcat( out[oInd++], "Z" );           //ADD Z AFTER b

    //START SECOND PRODUCTION

    strcpy( out[oInd], "Z=\0" );          //COPY Z=

    strcpy( &out[oInd][2], &str[3] );     //COPY a FROM str

    for( dpos=0; out[oInd][dpos]!='|'; dpos++ );   //FIND | IN SECOND PRODUCTION

    strcpy( &out[oInd][dpos], "Z|\0" );      //COPY Z| INPLACE OF | ( AFTER b )

    strcat( out[oInd],"e" );              //ADD EMPTY PRODUCTION

    cout<<out[0]<<endl<<out[1]<<endl;

    return 0;
}
