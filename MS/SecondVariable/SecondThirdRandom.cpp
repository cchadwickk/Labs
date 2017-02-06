#include<iostream>
#include<cstdlib>
#include<ctime>
#include<float.h>
#define noOfSims 100
#define noOfCust 100
using namespace std;
int main()
{
    srand(time(0));
    float arvl[noOfCust], srvc[noOfCust+1], del[noOfCust], comp[noOfCust], time[noOfCust+1], total, avg_sum=0, avg_custWait=0, avg_timeUtil=0;
    for(int z=0; z<noOfSims ; z++)
    {
        time[0]=0.0;
        del[0]=0.0;
        cout<<"\t" << z+1 << endl;
        for(int i=0;i<noOfCust;i++)      //GENERATE VALUES
        {
            arvl[i]=((float)rand()/RAND_MAX);
            srvc[i]=((float)rand()/RAND_MAX);
            cout<<arvl[i]<<" , "<<srvc[i]<<" | ";
        }
        cout<<endl;

        for(int j=0;j<noOfCust;j++)
            time[j+1]=time[j]+srvc[0];
        comp[0]=arvl[0]+del[0]+srvc[0];

        for(int k=1;k<=noOfCust;k++)     //CALCULATE DELAY, COMPLETION
        {
            if(time[k]>=comp[k-1])
                del[k]=0;
            else
                del[k]=comp[k-1]-time[k];
            comp[k]=time[k]+del[k]+srvc[k];
        }

        total=0;
        for(int i=0;i<noOfCust;i++)      //AVERAGE DELAYS FOR EACH SIMULATION
        {
            total=total+del[i];
        }
        avg_sum+=total/100;

        //FIRST VARIABLE FINISHED SECOND,THIRD BEGINS

        int compMax=noOfCust,timeMax=noOfCust;
        float lastEv = 0.0, sumCustWait = 0.0, timeUtil = 0.0;
        time[timeMax]=FLT_MAX;
        comp[compMax]=FLT_MAX;
        int timeCntr = 0, compCntr = 0, inQ = -1;

        while( timeCntr<timeMax ||  compCntr<compMax )
        {
            if(time[timeCntr]<comp[compCntr])             //ARRIVAL OCCURS
            {
                if(inQ >= 0){
                    timeUtil += time[timeCntr] - lastEv;
                    sumCustWait += (time[timeCntr] - lastEv) * inQ;   //CALCULATE AREA, UPDATE LAST EVENT
                }
                lastEv = time[timeCntr++];
                inQ++;
            }

            else                                         //DEPARTURE OCCURS
            {
                if(inQ >= 0){
                    timeUtil += comp[compCntr] - lastEv;
                    sumCustWait += (comp[compCntr]-lastEv) * inQ;   //CALCULATE AREA, UPDATE LAST EVENT
                }
                lastEv = comp[compCntr++];
                inQ--;
            }

        }
        cout<<"Average people in que "<<sumCustWait / lastEv<<endl;
        cout<<"Average server utilization "<<timeUtil / lastEv<<endl<<endl;
        avg_custWait +=  sumCustWait / lastEv;
        avg_timeUtil += timeUtil / lastEv;
    }

    cout<<"Average delay of simulations is : "<<avg_sum / noOfSims <<endl << endl;
    cout << "Average people in queue : " << avg_custWait / noOfSims << endl << endl;
    cout << "Average Server utilization : " << avg_timeUtil / noOfSims << endl;

    return 0;
}
