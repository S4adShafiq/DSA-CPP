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
    Node *ptr=head;
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=n;
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
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=n;
    n->next=head;
}
void DeleteAtHead(Node *&head){
    Node *ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    Node *todelete=head;
    ptr->next=head->next;
    delete todelete;

}
void Delete(Node *&head,int pos){
    Node *ptr=head;
    int counter=1;
    if(pos==1){
        DeleteAtHead(head);
        return;
    }
    while(counter!=pos-1){
        ptr=ptr->next;
        counter++;
    }
    Node *todelete=ptr->next;
    ptr->next=ptr->next->next;
    delete todelete;
}

void display(Node *&head){
    Node *temp=head;
    do{
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }while(temp->next!=head);
    cout<<endl;
}

int main (){
    Node *head=NULL;
    cout<<"Insertion at End"<<endl;
    InsertAtEnd(head,1); 
    InsertAtEnd(head,2); 
    InsertAtEnd(head,3); 
    InsertAtEnd(head,4); 
    display(head);
    cout<<"After insertion at Head"<<endl;
    InsertAtHead(head,0);
    display(head);
    cout <<"After Deletion at Position"<<endl;
    Delete(head,5);
    display(head);
}