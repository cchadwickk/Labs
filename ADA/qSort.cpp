#include<iostream>
using namespace std;
void exch(int &a,int &b)
{
int temp;
temp=a;
a=b;
b=temp;
}
void qsort(int arr[],int n)
{
int front=1,pivot=arr[0],rear=n;
while(front<=rear)
{
while(front<=rear)
{
if(arr[front]>pivot)
{break;}
}
while(front<=rear)
{
if(arr[rear]<pivot)
{
flag=0;exch(arr[front],arr[rear])
break;
rear--;
}
}
}
exch(arr[0],arr[rear]);
qsort(&arr[0],rear-1);
qsort(&arr[rear+1],n-rear-1);
}
int main()
{
int arr[30]={1,3,5,7,9,2,4,6,8,10};
qsort(arr,9);
for(int i=0;i<10;i++)
cout<<arr[i]<<" ";
}

