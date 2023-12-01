// Name:Muhammad Saad Shafiq
// Roll No: FA22-BSE-111-C


// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int data;
//     Node *next;
//     Node(int data){
//         this->data=data;
//         this->next=NULL;
//     }
// };

// void Enqueue(Node *&head,int data){
//     Node *n= new Node(data);
//     Node *ptr=head;
//     if(head==NULL){
//        head=n;
//        return;
//     }
//     while(ptr->next!=NULL){
//         ptr=ptr->next;
//     }
//     ptr->next=n;
//     n->next=NULL;
// }
// void Dequeue(Node *&head){
//     Node *ptr=head;
//     Node *todelete=ptr;
//     head=ptr->next;
//     delete todelete;
// }

// void display(Node *head){
//     Node *temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" -> ";
//         temp=temp->next;
//     }
//     cout<<endl;
// }

// int main (){
//     Node *head=NULL;
//     cout<<"Enqueueing "<<endl;
//     Enqueue(head,1);
//     Enqueue(head,2);
//     Enqueue(head,3);
//     Enqueue(head,4);
//     Enqueue(head,5);
//     Enqueue(head,6);
//     display(head);
//     cout<<"After Dequeueing "<<endl;
//     Dequeue(head);
//     Dequeue(head);
//     Dequeue(head);
//     display(head);
// }