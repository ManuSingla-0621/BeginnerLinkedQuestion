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
void Push(Node* &s,int data)
{
    Node* n=new Node(data);
    if(s==NULL)
    s=n;
    else
    {
        Node* temp=s;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=n;
    }
}
void Pop(Node* &s)
{
    if(s==NULL)
    cout<<"Stack UnderFlow"<<endl;
    else
    {
        Node* temp=s;
        s=temp->next;
        delete temp;
    }
}
int Top(Node* s)
{
    if(s==NULL)
    return -1;
    else
    return s->data;
}
int main()
{
  Node* s=NULL;
  Push(s,10);  
  Push(s,20);  
  Push(s,30);  
  Push(s,40);
  Pop(s);
  int ans=Top(s);
  cout<<ans<<endl;
  return 0;  
}