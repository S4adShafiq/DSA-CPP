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

void DeleteJosephusProblem(Node *&head,int pos){
    Node *ptr=head;
    Node *prev = NULL;
    int counter=1;
    do{
      if (counter == pos ){
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
    InsertAtEnd(head,1); 
    InsertAtEnd(head,2); 
    InsertAtEnd(head,3); 
    InsertAtEnd(head,4); 
    InsertAtEnd(head,5); 
    InsertAtEnd(head,6); 
    display(head);
    cout <<"After Deletion of Node by Josephus Problem "<<endl;
    DeleteJosephusProblem(head,2);
    DeleteJosephusProblem(head,2);
    DeleteJosephusProblem(head,2);
    DeleteJosephusProblem(head,2);
    display(head);
}