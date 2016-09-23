#include<iostream>
using namespace std;
struct node{int data; node *next;};
class q{
    node *top,*rear;
public:
    q()   //TOP POINTS TO LOCATION WHERE NEXT ELEMENT IS TO BE STORED
    {       //REAR POINTS TO THE ELEMENT TO BE DELETED
        top=new node;
        rear=top;
    }
    ~q()
    {
        node *t;
        while(rear!=top)
        {
            t=rear;
            rear=rear->next;
            delete t;
        }
    }
    int empt(){return (rear==top);}
    void enqueue(int);
    int dequeue();
    void display();
};
void q::enqueue(int t)
{
    top->data=t;
    top->next=new node;
    top=top->next;
}
int q::dequeue()
{
    if(empt())
    {   cout<<"Queue Empty";return -1;}
    else
    {
        int t;
        node *tt;
        t=rear->data;
        tt=rear;
        rear=rear->next;
        delete tt;
        return t;
    }
}
void q::display()
{
    node *x=rear;
    while(x!=top)
    {
        cout<<x->data<<" ";
        x=x->next;
    }
}
int main()
{
    int ch,val;
    q qq;
    while(1)
    {
        cout<<"\t\t1 enQ 2 deQ 3 View\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Element :";
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
        cout<<"Again (1=y/2=n)?";
        cin>>ch;
        if(ch!=1)
            break;
    }
    return 0;
}
