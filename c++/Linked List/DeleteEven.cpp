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
void DeleteEven(Node *&head){
    Node *ptr=head;
    Node *prev = NULL;
    do{
      if (ptr->data % 2 == 0 ){
            if(ptr == head){
                head=ptr->next;
            }
            Node *todelete=ptr;
            prev->next=ptr->next;
            ptr=ptr->next;
            delete todelete;
        }
        else{
            prev=ptr;
            ptr=ptr->next;
        }
    }while(ptr->next!=head);
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
    cout<<"Insertion "<<endl;
    InsertAtEnd(head,1); 
    InsertAtEnd(head,2); 
    InsertAtEnd(head,3); 
    InsertAtEnd(head,4); 
    InsertAtEnd(head,5); 
    InsertAtEnd(head,6); 
    display(head);
    cout <<"After Deletion of Even "<<endl;
    DeleteEven(head);
    display(head);
}