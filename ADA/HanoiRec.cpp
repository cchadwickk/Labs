#include<iostream>
using namespace std;
void hanoirec(int n,char src, char aux, char dest)
{
    if(n>0)
    {
        hanoirec(n-1,src,dest,aux);
        cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
        hanoirec(n-1,aux,src,dest);
    }
}
int main()
{
    int n;
    cin>>n;
    hanoirec(n,'S','A','D');
    return 0;
}
