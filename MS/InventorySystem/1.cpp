#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<float.h>
#define n 120
#define IIDMAX 0.15
#define IIDMIN 0.05
#define DMAX 4
#define DMIN 1
float max(float a, float b)
{
    if(a>b)
        return a;
    else return b;
}
float min(float a, float b)
{
    if(a<b)
        return a;
    return b;
}
using namespace std;
struct stationary{
    int s,S;
};
main()
{
    int s,S,K=32,i=3,h=1,pi=5,D,cost,Z,j;
    double I,curr,IID,IPlus,IMinus,deltime,IPlusAvg,IMinusAvg,avgCost,avgOfAvg,avgIPlusAvg,avgIMinusAvg;
    stationary stat[9] = {{20,40},{20,60},{20,80},{20,100},{40,60},{40,80},{40,100},{60,80},{60,100}};

    avgOfAvg=0;
    for(j=0;j<9;j++)            //LOOP FOR POLICIES
    {
        srand(time(0));
        s=stat[j].s;
        S=stat[j].S;
        avgCost=0;
        avgIPlusAvg=avgIMinusAvg=0;
        for(int i=0;i<100;i++)      //SIMULATION LOOP
        {
            I=S;
            curr=0;
            IPlus=IMinus=0;
            cost=0;
            while(1)           //REMEMBER TO ADD FOR GREATER THAN 120
            {

                IID=((float)rand()/(float)(RAND_MAX/0.1))+0.2;
                D=rand()%(DMAX-DMIN+1) + DMIN;

                if(curr+IID>n)                      //IF BUSINESS PERIOD ENDS
                    break;

                else if(curr+IID>deltime)           //NEW INVENTORY ARRIVES BEFORE NEXT DEMAND ?
                {
                    if(I<0)                         //IF ALREADY BACKLOG
                    {
                        IMinus+=deltime-curr*(-I);
                    }
                    else
                    {
                        IPlus+=deltime-curr*I;
                    }
                    I+=Z;
                    IID-=(deltime-curr);
                    curr=deltime;
                }

                else if(floor(curr+IID)>floor(IID))      //IF MONTH CHANGES
                {
                    if(I<s)
                    {
                        Z=S-I;
                        cost+=K+i*Z;
                        deltime=curr + ((float)rand()/(float)(RAND_MAX/0.5))+0.5;
                    }
                }


                if(I<0)                         //IF ALREADY BACKLOG
                {
                    IMinus+=IID*(-I);
                }
                else
                {
                    IPlus+=IID*I;
                }
                curr+=IID;
                I-=D;
            }
            IPlusAvg=IPlus/n;
            IMinusAvg=IMinus/n;
            cost/=n;
            cost+=IPlusAvg*h;
            cost+=IMinusAvg*pi;
            avgCost+=cost;
            avgIPlusAvg+=IPlusAvg;
            avgIMinusAvg+=IMinusAvg;
        }
        avgOfAvg+=avgCost/100;
        cout<<j+1<<" : "<<endl<<"Cost: "<<avgCost/100<<endl;
        cout<<avgIPlusAvg/100<<endl;
        cout<<avgIMinusAvg/100<<endl;

    }
    cout<<"Average of average "<<avgOfAvg/j;
    return 0;
}
