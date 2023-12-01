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
Node* insertAtMid(Node *head , Node *p, int data){
    Node *t = new Node(data);
    t->next = p->next;
    p->next = t;
    return head;
}
void print(Node *head){
    while(head!=NULL){
        cout <<head->data<<" ";
        head=head->next;
    }
}
void swapNodes(Node*& head, int val1, int val2) {
    Node* prev1 = nullptr;
    Node* prev2 = nullptr;
    Node* current = head;
    while (current) {
        if (current->data == val1) {
            prev1 = current;
        }
        if (current->data == val2) {
            prev2 = current;
        }
        current = current->next;
    }

    Node* temp = prev2->next;
    prev2->next = prev1->next;
    prev1->next = temp;
    
    if (prev1 == head) {
        head = prev2;
    } else if (prev2 == head) {
        head = prev1;
    }
}
int main (){

    Node *head= new Node(3);
    head=insert(head,5);
    head=insertAtEnd(head,8);
    head=insertAtMid(head,head->next,9);
    swapNodes(head,5,8);
    print(head);
}