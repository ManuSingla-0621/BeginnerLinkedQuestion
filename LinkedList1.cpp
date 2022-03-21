#include<iostream>
using namespace std;
class Node     // Creating the class which of Node type
{
    public:
    int data;
    Node* next;
    Node(int data)  //Constructor to Create Node.
    {
        this->data=data;
        this->next=NULL;
    }
};
void addFirst(Node* &s,int data) //Add First to the Linked List
{
   Node* n=new Node(data);
   if(s==NULL)
   {
       s=n;
   }
   else
   {
       n->next=s;
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
    }
}
void DeleteFirst(Node* &s)
{
   if(s==NULL)
   cout<<"UnderFlow"<<endl;
   else
   {
       Node* temp=s;
       s=temp->next;
       delete temp;
   }
}
void DeleteLast(Node* &s)
{
  if(s==NULL)
  cout<<"UnderFlow"<<endl;
  else
  {
      Node* t1=s;
      Node* t2=NULL;
      while(t1->next!=NULL)
      {
          t2=t1;
          t1=t1->next;
      }
      if(t2==NULL)
      s=NULL;
      else
      t2->next=NULL;
  }
}
void Display(Node* s)
{
 if(s==NULL)
 cout<<"Linked List is Empty..."<<endl;
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
    addLast(s,10);
    addLast(s,20);
    addLast(s,30);
    addLast(s,40);
    addLast(s,50);
    addFirst(s,0);
    DeleteFirst(s);
    DeleteLast(s);
    Display(s);
    return 0;
}