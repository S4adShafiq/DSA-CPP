#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev=NULL;
    Node* next=NULL;
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
void InsertAtHead(Node *&head,int data){
     Node *n=new Node (data);
     n->next=head;
     if(head!=NULL){
     n->prev=n;
     }
     head=n;

}
void InsertAtEnd(Node *&head,int data){
    Node *n=new Node (data);
    Node *ptr=head;
    if(head==NULL){
        InsertAtHead(head,data);
        return;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=n;
    n->prev=ptr;
}
void Display(Node *&head){
    Node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout <<endl;
}
int main (){
    Node *head=NULL;
    InsertAtEnd(head,1);
    InsertAtEnd(head,2);
    InsertAtEnd(head,3);
    InsertAtEnd(head,4);
    InsertAtHead(head,0);
    Display(head);
}