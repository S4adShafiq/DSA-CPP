#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
Node* insert(Node *head,int data){
    Node *t=new Node(data);
    t->next=head;
    return t;
}
Node* insertAtEnd(Node *head,int data){
    Node *t=new Node(data);
    Node *p = head;
    while(p-> next != NULL){
        p = p-> next;
    } 
    p->next = t;
    t->next = NULL;
    return head;
}
Node* insertAtMid(Node * head , Node *p, int data){
    Node *t = new Node(data);
    t->next = p->next;
    p->next = t;
    return head;
}
void print(Node *head){
    while(head!=NULL){
        cout <<head->data<<"->";
        head=head->next;
    }
}
void reversePrint(Node *head){
    if(head!=NULL){
        reversePrint(head->next);
         cout<<head->data <<"->";
    }
}
int main (){

    Node *head= new Node(3);
    head=insert(head,5);
    head=insertAtEnd(head,8);
    head=insertAtMid(head,head->next,9);
    print(head);
    cout<<endl;
    reversePrint(head);
}