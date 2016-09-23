#include<iostream>

using namespace std;

int partiton(int *A , int start , int last)
{
    int pivot , temp , counter , n=1;
    pivot = A[last];
    int pindex = start;
    for(counter = start ; counter < last ; counter++)
    {
        if(A[counter] <= pivot)
        {
            temp = A[pindex];
            A[pindex] = A[counter];
            A[counter] = temp;
            pindex++;
        }
    }

    temp = pivot;
    A[last]= A[pindex];
    A[pindex] = temp;
    /*cout<<"start="<<start<<" end="<<last<<endl;
    for(counter=start ; counter<=last ; counter++){
        cout<<A[counter]<<" ";
    }
    cout<<endl;*/
    return pindex;
}

void quick_sort(int *A , int start , int last)
{
    int pindex;
    if(start < last){
        pindex = partiton(A, start , last);
    //if(pindex>0)
        quick_sort(A , start , pindex-1);
    //if(pindex>0)
        quick_sort(A , pindex+1 , last);
    }
}

int main()
{
    int arr[5] , counter, n;
    cout<<"enter size: ";
    cin >> n;
    cout << "enter array elements: ";
    for(counter = 0 ; counter <n ; counter++){
        cin >> arr[counter];
    }
    //size_of=sizeof(arr)/sizeof(int);
    //cout<<size_of;
    cout<<"\nsorted array\n";
    quick_sort(arr , 0 , n-1);
    for(counter = 0 ; counter <n ; counter++){
        cout << arr[counter] << " ";
    }
}

