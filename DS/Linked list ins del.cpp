#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node* insertion(node *first, int info, int loc)
{
    node *ptr = new node ;
    node *originalfirst = first ;
    ptr -> data = info ;
    if( loc == 1 )
    {
        ptr -> next = first ;
        first = ptr ;
        return first;
    }
    else
    {
        for(int i=1 ; i<loc-1 ; i++)
        {
            first = first -> next;
        }
        ptr -> next = first -> next;
        first -> next = ptr;
        return originalfirst;
    }
}
node* deletion(node *first ,int loc)
{
    node *originalfirst = first;
    node *temp;
    if(loc == 1)
    {
        temp = first;
        first = first -> next;
        delete temp;
        return first;
    }
    else
    {
        for(int i=1 ; i<loc-1 ; i++)
        {
            first = first -> next;
        }
        temp = first -> next;
        first -> next = temp -> next;
        delete temp;
        return originalfirst;
    }
}
void display(node *first)
{
        cout<<"Array : ";
        while( first != NULL )
        {
            cout<<first->data<<" ";
            first=first->next;
        }
        cout<<"\n";
}
void deleteall(node *first)
{
    node *ptr;
    ptr = first;
    while(first != NULL)
    {
        first = first->next;
        delete ptr;
        ptr = first;
    }
}
int main()
{
    node *first = NULL;
    int choice, info, loc;
    while(1)
    {
        cout<<"Enter :\n\t1. Insertion\n\t2. Deletion\n\t3. Exit";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter info and location\n";
            cin>>info>>loc;
            first=insertion(first, info, loc);
            display(first);
            break;
        case 2:
            cout<<"Enter location to delete from\n";
            cin>>loc;
            first = deletion(first, loc);
            display(first);
            break;
        case 3:
            break;
        default:
            cout<<"WRONG INPUT\n";
            continue;
        }
        if(choice == 3)
            break;
    }
    deleteall(first);
    return 0;
}
