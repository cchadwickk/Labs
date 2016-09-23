#include<iostream>
#define ll long long int
using namespace std;

ll swapit(ll *a, ll *b){
    ll temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

ll Partition(ll *arr, ll l, ll h){
    ll pivot, pindex;
    pivot = arr[h];
    pindex = l;
    for(ll j=l; j<h; j++){
        if(arr[j] < pivot){
            //pindex++;
            swapit(&arr[pindex], &arr[j]);
            pindex++;
        }
    }
    swapit(&arr[pindex], &arr[h]);
    return pindex;
}

ll QuickSort(ll *arr, ll l, ll h){
    if(l < h){
        ll p = Partition(arr, l, h);
        QuickSort(arr, l, p-1);
        QuickSort(arr, p+1, h);
    }
}

int main(){
    ll n, arr[100];

    cout << "array size: ";
    cin >> n;
    cout << "enter array elements: ";
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    QuickSort(arr, 0, n-1);

    for(ll i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
