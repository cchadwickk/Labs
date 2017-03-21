#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<time.h>
#define tyme 100
#define packets 20
using namespace std;
bool comp(float a, float b){
    return a<b;
}
 
int findMin(float **times, int *startInd, int stats){
    int mini,flag=0,i;
    for(i=0;i<stats;i++)
    {
        if(startInd[i]<packets)
        {
            flag = 1;
            mini=i;
            break;
        }
    }
 
    if(!flag)
        return -1;
 
    for(i=0; i<stats; i++)
    {
        if( (times[i][startInd[i]] < times[mini][startInd[mini]]) &&(startInd[i]<packets))
        {
            mini = i;
        }
    }
    return mini;
}
main()
{
    srand(time(NULL));
 
    int stat,len,fail=0,*startInd,x,flag,cnt=0;
    float **times;
 
    cout<<"Enter number of stations";
    cin>>stat;
 
    times = new float*[stat];
    startInd = new int[stat];
    cout<<"Enter length of packet";
    cin>>len;
 
    for(int i=0; i<stat; i++)
    {
        times[i] = new float[packets];
 
        for(int j=0; j<packets; j++)
            times[i][j] = (float(rand())/RAND_MAX)*tyme;
 
        sort(&times[i][0],&times[i][packets],comp);
 
        startInd[i]=0;
    }
 
    for(int i=0;i<stat;i++){
        for(int j=0;j<packets;j++)
            cout<<times[i][j]<<" ";
        cout<<endl<<endl;
    }
 
    while((x = findMin(times, startInd, stat))!=-1)
    {
        flag =0;
        for(int j=0; j<stat; j++)
        {
            if( (times[j][startInd[j]] <= (times[x][startInd[x]]+len)) && (x!=j) &&(j<stat) &&(startInd[j]<packets))
            {
                //cout<<"Fail at "<<times[j][startInd[j]]<<"("<<j<<","<<startInd[j]<<")"<<" and "<<times[x][startInd[x]]<<"("<<x<<","<<startInd[x]<<")"<<endl;
                startInd[j]++;
                fail++;
                flag=1;
            }
        }
        startInd[x]++;
        if(flag)
            fail++;
    }
    cout<<"Fail: "<<fail<<" Total: "<<packets*stat;
    cout<<" Throughput: "<<( float(packets * stat) - float(fail) ) / float(packets * stat)<<endl;
    delete times;
    return 0;
}