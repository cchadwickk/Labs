#include<iostream>
using namespace std;
int recpower(int x,int y)
{
    if(y==1)
        return x;
    return (recpower(x,y-1)*x);
}
int series(int a,int n)
{
    if(n==1)
        return a;
    return series(a,n-1)+recpower(a,n);
}
int main()
{
    int a,n;
    cout<<"Enter a and n";
    cin>>a>>n;
    cout<<series(a,n);
    return 0;
}
