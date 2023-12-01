#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void InsertAtHead(Node *&head,int data){
    Node *n= new Node(data);
    n->next=head;
    head=n;
}
void InsertAtEnd(Node *&head,int data){
    Node *n= new Node(data);
    Node *ptr=head;
    if(head==NULL){
       InsertAtHead(head,data);
        return;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=n;
    n->next=NULL;
}
void EvenOdd(Node *&head){
    Node *odd=head;
    Node *even=head->next;
    Node *evenstart=even;
    while (odd->next!=NULL&&even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenstart;
    if(odd->next!=NULL){
        even->next=NULL;
    }
    
}
void display(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}

int main (){
    Node *head=NULL;
    cout<<"Insertion "<<endl;
    InsertAtEnd(head,1); 
    InsertAtEnd(head,2); 
    InsertAtEnd(head,3); 
    InsertAtEnd(head,4); 
    InsertAtEnd(head,5); 
    InsertAtEnd(head,6); 
    InsertAtEnd(head,7); 
    InsertAtEnd(head,8); 
    EvenOdd(head);
    display(head);
}