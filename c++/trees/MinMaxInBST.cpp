#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void LevelOrderTraversal(Node * root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * temp = q.front();
         q.pop();
        if(temp == NULL){
            cout<< endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<< temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}

Node * CreateBST(Node* root,int data){
    if(root==NULL){
        root =new Node(data);
        return root;
    }
    if(data > root->data){
        root->right=CreateBST(root->right,data);
    }
    else{
        root->left=CreateBST(root->left,data);
    }
    return root;
}

void InsertData(Node * &root){
    int data;
    cin>>data;
    while(data !=-1){
        root = CreateBST(root,data);
        cin>>data;
    }
}
Node * Min(Node * root){
    Node * temp= root;
    while(temp->left!= NULL){
        temp=temp->left;
    }
    return temp;
}
Node * Max(Node * root){
    Node * temp= root;
    while(temp->right!= NULL){
        temp=temp->right;
    }
    return temp;
}
int main(){
    Node * root= NULL;
    cout<<"Enter To create BST"<<endl;
    InsertData(root);
    cout<<"Printing the BST"<<endl;
    LevelOrderTraversal(root);
    cout<<"The Minimum Value is : "<<Min(root)->data<<endl;
    cout<<"The Maximum Value is : "<<Max(root)->data;
    return 0;
}