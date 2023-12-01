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
void DeleteEvenNode(Node *&head){
    Node *ptr=head;
    Node *prev = NULL;
    int counter=1;
    do{
      if (counter%2 == 0 ){
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
        counter++;
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
    InsertAtEnd(head,7); 
    InsertAtEnd(head,11); 
    InsertAtEnd(head,18); 
    InsertAtEnd(head,37); 
    InsertAtEnd(head,69); 
    InsertAtEnd(head,77); 
    display(head);
    cout <<"After Deletion of Even Postion Node"<<endl;
    DeleteEvenNode(head);
    display(head);
}