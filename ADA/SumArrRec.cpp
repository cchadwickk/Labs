#include<iostream>
#define SIZEARR 30
using namespace std;
int recadd(int arr[SIZEARR],int n)
{
    if(n==1)
        return arr[0];
    return (recadd(arr,n-1)+arr[n-1]);
}
int main()
{
    int arr[SIZEARR],n;
    cout<<"Enter n";
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    n=recadd(arr,n);
    cout<<n;
}
