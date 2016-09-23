#include<iostream>
using namespace std;
class q{
    int str[30];
    int top,rear;
    int limit;
public:
    q()   //TOP POINTS TO LAST INSERTED ELEMENT
    {       //REAR POINTS TO THE ELEMENT TO BE DELETED
        top=-1;
        rear=0;
        limit=30;
    }
    int full(){return (top==limit-1);}
    int empt(){return (rear>top);}
    void enqueue(int);
    int dequeue();
    void display();
};
void q::enqueue(int t)
{
    if(full())
        cout<<"No More Space";
    else
        str[++top]=t;
}
int q::dequeue()
{
    if(empt())
        cout<<"Queue Empty";
    else
    {
        if(rear==top)
        {
            int temp;
            temp=str[rear];
            rear=0;
            top=-1;
            return temp;
        }
        return str[rear++];
    }
}
void q::display()
{
    for(int i=rear;i<=top;i++)
        cout<<str[i]<<" ";
    cout<<endl;
}
int main()
{
    int ch,val;
    q qq;
    do{
        cout<<"\t\t1 enQ 2 deQ 3 view\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter element";
                cin>>val;
                qq.enqueue(val);
                break;
            case 2:
                val=qq.dequeue();
                cout<<"Removed : "<<val;
                break;
            case 3:
                qq.display();
        }
        cout<<"Again (1 to exit)?";
        cin>>ch;
    }while(ch);
    return 0;
}
