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
Node *head=NULL; 
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
int Peek(Node *&head){
    return head->data;
}
void display(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}
bool isEmpty()
{
    return head == NULL;
}
int Precedence(char s){
    if(s=='*'||s=='/'){
        return 2;
    }
    else if(s=='+'||s=='-'){
        return 1;
    }
    return 0;
}
string infToPost(string inf){
    string post;
    string output;
    for(char c : inf){
        if(isdigit(c)){
            output+=c;
        }
        else{
            if(!output.empty()){
                post+=output+" ";
                output=" ";
            }
            if( c == ' '){
                continue;
            }
            if(c == '('){
                Push(head,c);
            }
            if(c==')'){
                while(Peek(head)!='('){
                    post+=Peek(head);
                    Pop(head);
                }
                Pop(head);
            }
            else{
                while(Precedence(c)<=Precedence(Peek(head))){
                    post+=Peek(head);
                    Pop(head);
                }
                 Push(head,c);
            }
        } 
    }
     if(!output.empty()){
         post += output + " ";
        }
      while (!isEmpty())
    {
        post += Peek(head);
        post += " ";
        Pop(head);
    }
    return post;
}
int main (){
    string infExp,postExp;
    cout << "Enter an infix expression: ";
    getline(cin, infExp);
    postExp=infToPost(infExp);
    cout<<"Postfix Expression is : "<<postExp;
}