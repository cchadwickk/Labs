#include<iostream>
#define SIZEARR 30
using namespace std;
void sel_sort(int arr[SIZEARR],int n){
    int temp,smallpos;
    for(int i=0;i<n-1;i++)
    {
        smallpos=i;
        temp=arr[i];
        for(int j=i;j<n;j++)
        {
            if(arr[j]<temp)
            {
                smallpos=j;
                temp=arr[j];
            }
        }
        arr[smallpos]=arr[i];
        arr[i]=temp;
    }
}
void ins_sort(int arr[SIZEARR],int n){
    int temp;
    for(int i=1;i<n;i++)
    {
        for(int j=i;((arr[j-1]>arr[j])&&(j>0));j--)
        {
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }
    }
}
int main(){
    int arr[SIZEARR],n,ch;
    do{
        cout<<"Enter size of array\n";
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"Enter 1 for selection 2 for insertion sort\n";
        cin>>ch;
        if(ch==1)
            sel_sort(arr,n);
        else if(ch==2)
            ins_sort(arr,n);
        else
        {
            cout<<"INVALID INPUT";
            return 1;
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        cout<<"Once more ? (0=YES)\n";
        cin>>ch;
    }while(!ch);
    return 0;
}
