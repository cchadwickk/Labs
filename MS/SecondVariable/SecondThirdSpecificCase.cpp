#include<iostream>
#include<float.h>
using namespace std;
main()
{
    float arr[10] = {0.4, 1.6, 2.1, 3.8, 4.0, 5.6, 5.8, 7.2, FLT_MAX};
    float comp[10] = {2.4, 3.1, 3.3, 4.9, 8.6, FLT_MAX};
    float lastEv = 0.0, sumCustWait = 0.0, timeUtil = 0.0;

    int arrMax = 8, compMax = 5;
    int arrCntr = 0, compCntr = 0, inQ = -1;

    while( arrCntr<arrMax ||  compCntr<compMax )
    {
        if(arr[arrCntr]<comp[compCntr])             //ARRIVAL OCCURS
        {
            if(inQ >= 0){
                timeUtil += arr[arrCntr] - lastEv;
                sumCustWait += (arr[arrCntr] - lastEv) * inQ;   //CALCULATE AREA, UPDATE LAST EVENT
            }
            lastEv = arr[arrCntr++];
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
    cout << "Average people in queue: " << sumCustWait << " / " << lastEv << " = " << sumCustWait / lastEv << endl << endl;
    cout << "Server utilization: " << timeUtil << " / " << lastEv << " = " << timeUtil / lastEv << endl;
    return 0;
}
