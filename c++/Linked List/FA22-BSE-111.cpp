// Name: Muhammad Saad Shafiq
// Roll No: FA22-BSE-111
// Section: C

//                                     Home Task 1


// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int data;
//     Node *prev=NULL;
//     Node* next=NULL;
//     Node(int data){
//         this->data=data;
//         this->prev=NULL;
//         this->next=NULL;
//     }
// };

// void InsertAtHead(Node *&head,int data){
//      Node *n=new Node (data);
//      n->next=head;
//      if(head!=NULL){
//      n->prev=n;
//      }
//      head=n;

// }
// void InsertAtEnd(Node *&head,int data){
//     Node *n=new Node (data);
//     Node *ptr=head;
//     if(head==NULL){
//         InsertAtHead(head,data);
//         return;
//     }
//     while(ptr->next!=NULL){
//         ptr=ptr->next;
//     }
//     ptr->next=n;
//     n->prev=ptr;
// }
// void Display(Node *&head){
//     Node *ptr=head;
//     while(ptr!=NULL){
//         cout<<ptr->data<<"->";
//         ptr=ptr->next;
//     }
//     cout <<endl;
// }
// void ReverseNode(Node *&head)
// {
//     Node *prevPtr = NULL;
//     Node *currPtr = head;
//     Node *nxtPtr;

//     while (currPtr != NULL)
//     {
//         nxtPtr = currPtr->next;
//         currPtr->next = prevPtr;

//         prevPtr = currPtr;
//         currPtr = nxtPtr;
//     }
//     head = prevPtr;
// }
// int main (){
//     Node *head=NULL;
//     InsertAtEnd(head,1);
//     InsertAtEnd(head,2);
//     InsertAtEnd(head,3);
//     InsertAtEnd(head,4);
//     InsertAtHead(head,0);
//     Display(head);
//     ReverseNode(head);
//     Display(head);
// }


//                                     Home Task 2



// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int data;
//     Node *prev=NULL;
//     Node* next=NULL;
//     Node(int data){
//         this->data=data;
//         this->prev=NULL;
//         this->next=NULL;
//     }
// };
// void InsertAtHead(Node *&head,int data){
//      Node *n=new Node (data);
//      n->next=head;
//      if(head!=NULL){
//      n->prev=n;
//      }
//      head=n;

// }
// void InsertAtEnd(Node *&head,int data){
//     Node *n=new Node (data);
//     Node *ptr=head;
//     if(head==NULL){
//         InsertAtHead(head,data);
//         return;
//     }
//     while(ptr->next!=NULL){
//         ptr=ptr->next;
//     }
//     ptr->next=n;
//     n->prev=ptr;
// }
// void Display(Node *&head){
//     Node *ptr=head;
//     while(ptr!=NULL){
//         cout<<ptr->data<<"->";
//         ptr=ptr->next;
//     }
//     cout <<endl;
// }
// void EvenOdd(Node *&head){
//     Node *odd=NULL;
//     Node *even=NULL;
//     Node *current=head;
//     while (current!=NULL)
//     {
//         if(current->data%2==0){
//             InsertAtEnd(even,current->data);
//         }
//         else{
//             InsertAtEnd(odd,current->data);
//         }
//         current = current->next;
//     }
//     cout<<"Even Values: "<<endl;
//     Display(even);
//     cout<<"Odd Values: "<<endl;
//     Display(odd);
// }
// int main (){
//     Node *head=NULL;
//     InsertAtEnd(head,1);
//     InsertAtEnd(head,2);
//     InsertAtEnd(head,3);
//     InsertAtEnd(head,4);
//     InsertAtHead(head,0);
//     Display(head);
//     EvenOdd(head);
//     }


//                                          Home Task 3



// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int data;
//     Node *prev=NULL;
//     Node* next=NULL;
//     Node(int data){
//         this->data=data;
//         this->prev=NULL;
//         this->next=NULL;
//     }
// };
// void InsertAtHead(Node *&head,int data){
//      Node *n=new Node (data);
//      n->next=head;
//      if(head!=NULL){
//      n->prev=n;
//      }
//      head=n;

// }
// void InsertAtEnd(Node *&head,int data){
//     Node *n=new Node (data);
//     Node *ptr=head;
//     if(head==NULL){
//         InsertAtHead(head,data);
//         return;
//     }
//     while(ptr->next!=NULL){
//         ptr=ptr->next;
//     }
//     ptr->next=n;
//     n->prev=ptr;
// }
// void Display(Node *&head){
//     Node *ptr=head;
//     while(ptr!=NULL){
//         cout<<ptr->data<<"->";
//         ptr=ptr->next;
//     }
//     cout <<endl;
// }
// Node *swapNodes(Node *head, int value1, int value2)
// {
//     if (value1 == value2)
//     {
//         cout << "Values are the same, no need to swap nodes." << endl;
//         return head;
//     }

//     Node *prev1 = nullptr;
//     Node *prev2 = nullptr;
//     Node *curr1 = head;
//     Node *curr2 = head;

//     while (curr1 != nullptr && curr1->data != value1)
//     {
//         prev1 = curr1;
//         curr1 = curr1->next;
//     }

//     while (curr2 != nullptr && curr2->data != value2)
//     {
//         prev2 = curr2;
//         curr2 = curr2->next;
//     }

//     if (curr1 == nullptr || curr2 == nullptr)
//     {
//         cout << "One or both values not found in the list." << endl;
//         return head;
//     }

//     if (prev1 != nullptr)
//     {
//         prev1->next = curr2;
//     }
//     else
//     {
//         head = curr2;
//     }

//     if (prev2 != nullptr)
//     {
//         prev2->next = curr1;
//     }
//     else
//     {
//         head = curr1;
//     }

//     Node *tempNext = curr1->next;
//     curr1->next = curr2->next;
//     curr2->next = tempNext;

//     Node *tempPrev = curr1->prev;
//     curr1->prev = curr2->prev;
//     curr2->prev = tempPrev;

//     return head;
// }
// int main (){
//     Node *head=NULL;
//     InsertAtEnd(head,1);
//     InsertAtEnd(head,2);
//     InsertAtEnd(head,3);
//     InsertAtEnd(head,4);
//     InsertAtHead(head,0);
//     Display(head);
//     head=swapNodes(head,1,4);
//     Display(head);
// }