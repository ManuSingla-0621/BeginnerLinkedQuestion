#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->prev=NULL;
        this->data=data;
        this->next=NULL;
    }
};
void addFirst(Node* &s,int data)
{
Node* n=new Node(data);
if(s==NULL)
{
    s=n;
}
else
{
    n->next=s;
    n->next->prev=n;
    s=n;
}
}
void addLast(Node* &s,int data)
{
Node* n=new Node(data);
if(s==NULL)
{
    s=n;
}
else
{
    Node* temp=s;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=n;
    n->prev=temp;
}
}
void DeleteFirst(Node* &s)
{
if(s==NULL)
cout<<"UnderFlow"<<endl;
else if(s->next==NULL)
{
    delete s;
    s=NULL;
}
else
{
    Node* temp=s;
    s=temp->next;
    s->prev=NULL;
    delete temp;
}
}
void DeleteLast(Node* &s)
{
if(s==NULL)
cout<<"Linked List is empty.."<<endl;
else if(s->next==NULL)
{
    delete s;
    s=NULL;
}
else
{
    Node* temp=s;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->prev->next=NULL;
    temp->prev=NULL;
    delete temp;
}
}
void Display(Node* s)
{
 if(s==NULL)
 cout<<"Doubly Linked List is empty..."<<endl;
 else
 {
     Node* temp=s;
     while(temp!=NULL)
     {
         cout<<temp->data<<"->";
         temp=temp->next;
     }
     cout<<"NULL"<<endl;
 }
}
int main()
{
    Node* s=NULL;
    addFirst(s,10);
    addFirst(s,20);
    addFirst(s,30);
    addFirst(s,40);
    Display(s);
    addLast(s,50);
    Display(s);
    DeleteFirst(s);
    DeleteFirst(s);
    DeleteFirst(s);
    DeleteFirst(s);
    Display(s);
    DeleteLast(s);
    Display(s);
    return 0;
}