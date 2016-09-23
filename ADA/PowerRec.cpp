#include<iostream>
#define SIZEARR 30
using namespace std;
int recpower(int x,int y)
{
    if(y==1)
        return x;
    return (recpower(x,y-1)*x);
}
int rec_less_complex(int x,int y)
{
    if(y==1)
        return x;
    else if(y%2==0)
        return rec_less_complex(x*x,y/2);
    else
        return (rec_less_complex(x*x,y/2)*x);
}
int main()
{
    int x,y;
    cout<<"Enter x,y for x^y\n";
    cin>>x>>y;
    cout<<rec_less_complex(x,y);
    return 0;
}
