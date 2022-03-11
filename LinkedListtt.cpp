#include<iostream>
using namespace std;
int size=0;
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
        s=n;
    }
    else
    {
        n->next=s;
        s=n;
    }
    size++;
}
void addLast(Node* &s,int data)
{
    Node* n=new Node(data);
    if(s==NULL)
    {
        s=n;
    }
    else{
        Node* temp=s;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
    size++;
}
void RemoveFirst(Node* &s)
{
    if(s==NULL)
    {
        cout<<"Linked lIst is empty.."<<endl;
        return;
    }
    else
    {
        Node* temp=s;
        s=temp->next;
        free(temp);
    }
}
void RemoveLast(Node* &s)
{
    if(s==NULL)
    {
        cout<<"Linked List is Empty.."<<endl;
        return;
    }
    else{
        Node* temp=s;
        Node* tmp=NULL;
        while(temp->next!=NULL)
        {
            tmp=temp;
            temp=temp->next;
        }
        if(tmp==NULL)
        s=NULL;
        else
        tmp->next=NULL;
    }
}
void RemoveIndex(Node* &s,int index)
{
    if(index==0)
    RemoveFirst(s);
    else if(index<0 || index>size)
    cout<<"Invalid Index"<<endl;
    else if(index==(size-1))
    RemoveLast(s);
    else
    {
        Node* temp=s;
        Node* prev=NULL;
        int count=0;
        while(temp!=NULL)
        {
          if(count==index)
          {
            Node* tmp=temp;
            prev->next=temp->next;
            delete tmp;
            break;
          }
         prev=temp;
         count++;
         temp=temp->next;
        }
    }

}
void addIndex(Node* &s,int index,int data)
{
    if(index==0)
    addFirst(s,data);
    else if(index<0 || index>size)
    cout<<"Invalid Index"<<endl;
    else if(index==(size))
    addLast(s,data);
    else
    {
        Node* n=new Node(data);
        Node* temp=s;
        Node* prev=NULL;
        int count=0;
        while(temp!=NULL)
        {
            if(count==index)
            {
              n->next=temp;
              prev->next=n;
              break;
            }
            count++;
            prev=temp;
            temp=temp->next;
        }
    }
    size++;
}
void Value(Node* s,int index)
{
    if(size==0)
    cout<<"Linked List is empty..."<<endl;
    else if(index>=size || index<0)
    {
      cout<<"Invalid Index"<<endl;
    }
    else{
         Node* temp=s;
         int count=0;
         while(temp!=NULL)
         {
              if(count==index)
              {
                  cout<<temp->data<<endl;
                  break;
              }
              count++;
              temp=temp->next;
         }
    }
}
int Middle(Node* s)
{
    Node* fast=s;
    Node* slow=s;
    while(fast!=NULL && slow!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }
    return slow->data;
}
Node* addTwo(Node* l1,Node* l2)
{
 if(l1!=NULL && l2==NULL)
 return l1;
 else if(l2!=NULL && l1==NULL)
 return l2;
 else
 {
     Node* dummy=new Node(0);
     Node* ans=dummy;
     int carry=0;
     while(l1!=NULL || l2!=NULL || carry)
     {
         int sum=0;
         if(l1!=NULL)
         {
             sum+=l1->data;
             l1=l1->next;
         }
         if(l2!=NULL)
         {
             sum+=l2->data;
             l2=l2->next;
         }
         sum+=carry;
         carry=sum/10;
         Node* temp=new Node(sum%10);
         ans->next=temp;
         ans=ans->next;
     }
     return dummy->next;
 }
}
Node* Reverse(Node* &s)
{
    Node* nextptr=s;
    Node* current=s;
    Node* prev=NULL;
    while(nextptr!=NULL)
    {
        nextptr=current->next;
        current->next=prev;
        prev=current;
        current=nextptr;
    }
    return prev;
}
bool Palindrome(Node* s)
{
    Node* fast=s->next;
    Node* slow=s;
    while(fast!=NULL && slow!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* temp_second=Reverse(slow->next);
    slow->next=NULL;
    Node* temp=s;
    while(temp!=NULL)
    {
     if(temp->data!=temp_second->data)
     return false;
     temp=temp->next;
     temp_second=temp_second->next;
    }
 return true;
}
void RemoveNthFromEnd(Node* &s,int n)
{
    if(n>size || n<=0)
    cout<<"Invalid";
    else if(n==size)
    RemoveFirst(s);
    else
    {
        int index=size-n;
        RemoveIndex(s,index);
    }
}
void RemovefromSorted(Node* &s)
{
    Node* temp=s;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            temp->next=temp->next->next;
        }
        else
        {
            temp=temp->next;
        }
    }
}
Node* getNode(Node* &s,int idx)
{
Node* temp=s;
for(int i=0;i<idx;i++)
temp=temp->next;
return temp;
}
void ReverseThroughData(Node* &s)
{
    int low=0;
    int high=size-1;
    while(low<high)
    {
        Node* l=getNode(s,low);
        Node* r=getNode(s,high);
        int temp=l->data;
        l->data=r->data;
        r->data=temp;
        low++;
        high--;
    }
}
Node* Merge(Node* l1,Node* l2)
{
 if(l1!=NULL && l2==NULL)
 return l1;
 else if(l2!=NULL && l1==NULL)
 return l2;
 Node* dummy=new Node(0);
 Node* ans=dummy;
 while(l1!=NULL && l2!=NULL)
 {
     if(l1->data<=l2->data)
     {
         ans->next=new Node(l1->data);
         ans=ans->next;
         l1=l1->next;
     }
     else
     {
         ans->next=new Node(l2->data);
         ans=ans->next;
         l2=l2->next;
     }
 }
 if(l1!=NULL)
 {
     ans->next=l1;
 }
 if(l2!=NULL)
 {
     ans->next=l2;
 }
 return dummy->next;
}
void Display(Node* s)
{
    if(s==NULL)
    {
        cout<<"Linked List is Empty..."<<endl;
        return;
    }
    Node* temp=s;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* s=NULL;
    addLast(s,1);
    addLast(s,2);
    addLast(s,6);
    addLast(s,9);
    Node* p=NULL;
    addLast(p,0);
    addLast(p,3);
    addLast(p,7);
    Display(s);
    Display(p);
    Node* ans=Merge(s,p);
    Display(ans);
    return 0;
}