#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#define ele 100
#define maxt 300
#define maxser 10
#define noOfSims 100
using namespace std;
struct ArrOfTwoEle{
    int t,ser;
};
class queueing{
    ArrOfTwoEle arr[ele+1];
    int del[ele+1],comp[ele+1];
    int len;
public:
    queueing()
    {
        for(int i=0; i<(ele+1) ; i++){del[i]=0;comp[i]=0;}
    }

    void srt(){  //SORT USING INSERTION SORT
        ArrOfTwoEle temp;
        int j;
        for(int i=2;i<=len;i++)
        {
            temp=arr[i];
            for( j=i-1; (j>=1)&&(arr[j].t>=temp.t); j--)
            {
                arr[j+1]=arr[j];
            }
            arr[j+1]=temp;
        }
    }

    void enter(int c[],int d[],int n){ //TO COPY ENTER TIME AND SERVICE TIME
        len=n;
        arr[0].t=0;
        arr[0].ser=0;
        for(int i=1;i<=n;i++)
        {
            arr[i].t=c[i];
            arr[i].ser=d[i];
        }
        srt();
    }

    void print(){
        int i;
        cout<<"T: ";
        for(i=1;i<=len;i++)
            cout<<arr[i].t<<" ";
        cout<<endl<<"S: ";
        for(i=1;i<=len;i++)
            cout<<arr[i].ser<<" ";
        cout<<endl<<endl;
    }

    void calctimes(){    //CALCULATE TIMES
        for(int i=1;i<=len;i++)
        {
            if(arr[i].t<comp[i-1])
                comp[i]=comp[i-1]+arr[i].ser;
            else
                comp[i]=arr[i].t+arr[i].ser;
        }
        for(int i=1;i<=len;i++)
        {
            del[i]=comp[i]-arr[i].t-arr[i].ser; //ADDED SERVICE SUBTRACTION
        }
    }

    float retavgdelay(){
        float retval=0;
        for(int i=1;i<=len;i++)
            retval+=del[i];
        return retval/float(len);
    }
};
main()
{
    queueing a;
    int t[ele+1], ser[ele+1],i ,j;
    float del[noOfSims], avgdel=0;
    srand(time(NULL));
    for(i=0; i<noOfSims;i++)
    {
        for(j=1;j<=ele;j++)
            t[j]=rand()%maxt;
        for(j=1;j<=ele;j++)
            ser[j]=rand()%maxser;
        a.enter(t,ser,ele);
        a.print();
        a.calctimes();
        del[i]=a.retavgdelay();
    }
    cout<<"Delays:\n";
    for(i=0;i<noOfSims;i++)
        cout<<del[i]<<" ";
    cout<<"\n";
    cout<<"Average Delay:\n";
    for(j=0;j<noOfSims;j++)
    {
        avgdel+=del[j];
    }
    avgdel=avgdel/noOfSims;
    cout<<avgdel<<endl;
    return 0;
}
