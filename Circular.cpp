#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void addFirst(Node* &s,int data)
{
    Node* n=new Node(data);
    if(s==NULL)
    {
        n->next=n;
        s=n;
    }
    else
    {
        n->next=s->next;
        s->next=n;
    }
}
void addLast(Node* &s,int data)
{
    Node* n=new Node(data);
    if(s==NULL)
    {
        n->next=n;
        s=n;
    }
    else
    {
        n->next=s->next;
        s->next=n;
        s=n;
    }
}
void DeleteFirst(Node* &s)
{
   if(s==NULL)
   cout<<"Linked List is empty..."<<endl;
   else if(s->next==NULL)
   {
       delete s;
       s=NULL;
   }
   else
   {
       Node* temp=s->next;
       s->next=temp->next;
       delete temp;
   }
}
void DeleteLast(Node* &s)
{
   if(s==NULL)
   cout<<"Linked List is empty..."<<endl;
   else if(s->next==NULL)
   {
       delete s;
       s=NULL;
   }
   else{
       Node* temp=s->next;
       while(temp->next!=s)
       {
           temp=temp->next;
       }
       Node* p=s;
       temp->next=s->next;
       delete s;
       s=temp;
   }
}
void Display(Node* s)
{
    if(s==NULL)
    cout<<"Circular Linked List is Empty.."<<endl;
    else
    {
        Node* temp=s->next;
        while(temp!=s)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<" ";
        cout<<endl;
    }
}
int main()
{
    Node* s=NULL;
    addLast(s,10);
    addLast(s,20);
    addLast(s,30);
    addLast(s,40);
    Display(s);
    DeleteLast(s);
    Display(s);
    DeleteFirst(s);
    Display(s);
    return 0;
}