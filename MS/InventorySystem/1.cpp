#include<iostream>
#include<fstream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<float.h>
#include <iomanip>
#define n 120
#define DMAX 4
#define DMIN 1
using namespace std;
struct stationary{
    int s,S;
};
main()
{
    int s,S,K=32,i=3,h=1,pi=5,D,cost,Z,j;
    double I,curr,IID,IPlus,IMinus,deltime,IPlusAvg,IMinusAvg,avgCost,avgOfAvg,avgIPlusAvg,avgIMinusAvg;
    stationary stat[9] = {{20,40},{20,60},{20,80},{20,100},{40,60},{40,80},{40,100},{60,80},{60,100}};
    //ofstream out("abc.txt");
    avgOfAvg=0;
    srand(time(0));
    for(j=0;j<9;j++)            //LOOP FOR POLICIES
    {
        //out<<endl<<endl<<endl<<"\t\t"<<j<<" POLICY"<<endl<<endl<<endl;
        s=stat[j].s;
        S=stat[j].S;
        avgCost=0;
        avgIPlusAvg=avgIMinusAvg=0;
        for(int l=0;l<100;l++)      //SIMULATION LOOP
        {
            //out<<endl<<endl<<"\t\t"<<l<<" SIM"<<endl<<endl;
            I=S;
            curr=0.0001;
            IPlus=IMinus=0;
            cost=0;

            while(1)           //REMEMBER TO ADD FOR GREATER THAN 120
            {

                IID=((float)rand()/(float)(RAND_MAX/0.1)+0.05);
                D=rand()%(DMAX-DMIN+1) + DMIN;
                //out<<setprecision(3)<<"\tI: "<<setprecision(3)<<I<<"\tCurr: "<<setprecision(3)<<curr<<"\tIID: "<<setprecision(3)<<IID<<"\tIPlus: "<<setprecision(4)<<IPlus<<"\tIMinus: "<<setprecision(4)<<IMinus<<endl<<endl;
                if(curr+IID>n)                      //IF BUSINESS PERIOD ENDS
                    break;

                else if((curr+IID)>deltime)           //NEW INVENTORY ARRIVES BEFORE NEXT DEMAND ?
                {
                    if(I<0)                         //IF ALREADY BACKLOG
                        IMinus+=((deltime-curr)*(-I));
                    else
                        IPlus+=((deltime-curr)*I);
                    I+=Z;
                    IID-=(deltime-curr);
                    curr=deltime;
                    deltime=INT_MAX;
                }

                else if( (floor(curr+IID)>floor(curr))&&(I<s) )      //IF MONTH CHANGES, AND INV IS LESS THAN THRESHHOLD
                {
                        Z=S-I;
                        cost+=K+i*Z;
                        deltime=((float)rand()/(float)(RAND_MAX/0.5))+0.5;
                        deltime+=floor(curr+IID) ;
                }


                if(I<0)                         //IF ALREADY BACKLOG
                    IMinus+=(IID*(-I));
                else
                    IPlus+=(IID*I);
                curr+=IID;
                I-=D;
            }

            if(I<0)
                IMinus+=((n-curr)*(-I));
            else
                IPlus+=((n-curr)*I);

            IPlusAvg=IPlus/n;
            IMinusAvg=IMinus/n;
            cost/=n;
            cost+=(IPlusAvg*h);
            cost+=(IMinusAvg*pi);
            avgCost+=cost;
            avgIPlusAvg+=IPlusAvg;
            avgIMinusAvg+=IMinusAvg;
        }
        avgOfAvg+=(avgCost/100);
        cout<<j+1<<" : "<<endl<<"Cost: "<<avgCost/100<<endl;
        cout<<"IPlus: "<<avgIPlusAvg/100<<endl;
        cout<<"IMinus: "<<avgIMinusAvg/100<<endl;

    }
    cout<<"Average of average "<<avgOfAvg/j;
    return 0;
}
