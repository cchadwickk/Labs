#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand(time(0));
    float arvl[100],srvc[101],del[100],comp[100],time[101],avg[100],total,avg_sum=0;
    for(int z=0; z<100; z++)
    {
        time[0]=0.0;
        del[0]=0.0;
        for(int i=0;i<100;i++)      //GENERATE VALUES
        {
            arvl[i]=((float)rand()/RAND_MAX);
            srvc[i]=((float)rand()/RAND_MAX);
            //cout<<arvl[i]<<" "<<srvc[i]<<endl;
        }

        for(int j=0;j<100;j++)
            time[j+1]=time[j]+srvc[0];
        comp[0]=arvl[0]+del[0]+srvc[0];

        for(int k=1;k<=100;k++)     //CALCULATE DELAY, COMPLETION
        {
            if(time[k]>=comp[k-1])
                del[k]=0;
            else
                del[k]=comp[k-1]-time[k];
            comp[k]=time[k]+del[k]+srvc[k];
        }

        total=0;
        for(int i=0;i<100;i++)      //AVERAGE DELAYS FOR EACH SIMULATION
        {
            total=total+del[i];
        }
        avg[z]=total/100;
    }

    for(int x=0;x<100;x++)          //AVERAGE OF AVERAGE
    {
        avg_sum=avg_sum+avg[x];
    }
    cout<<"\nAverage delay of simulations is :\t"<<avg_sum/100;

    return 0;
}
