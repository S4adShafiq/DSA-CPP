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

void Push(Node *&head,int data){
    Node *n= new Node(data);
    Node *ptr=head;
    if(head==NULL){
       head=n;
       return;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=n;
    n->next=NULL;
}
void Pop(Node *&head){
    Node *ptr=head;
    Node *prev=NULL;
    while(ptr->next!=NULL){
        prev=ptr;
        ptr=ptr->next;
    }
    Node *todelete=ptr;
    prev->next=NULL;
    ptr=prev->next;
    delete todelete;
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
    cout<<"Pushing "<<endl;
    Push(head,1);
    Push(head,2);
    Push(head,3);
    Push(head,4);
    Push(head,5);
    Push(head,6);
    display(head);
    cout<<"Poping "<<endl;
    Pop(head);
    Pop(head);
    display(head);
}