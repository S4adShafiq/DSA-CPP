#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        Node* left=NULL;
        Node* right=NULL;
    }
};

Node * Build(Node *root){
    int data;
    cout<<"Enter Data: "<<endl;
    cin>>data;
    root=new Node (data);

    if(data==-1){
        return NULL;
    }

    cout <<"Enter in LEFT of Root : "<< data<<endl;
    root->left=Build(root->left);
    cout <<"Enter in RIGHT of Root : "<< data<<endl;
    root->right=Build(root->right);
    return root; 
}

void Postorder(Node * root){
    if(root == NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout <<root->data<<" ";
}

int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root=NULL;
    root=Build(root);
    Postorder(root);
    return 0;
}