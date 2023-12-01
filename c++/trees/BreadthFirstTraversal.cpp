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

int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root=NULL;
    root=Build(root);
    LevelOrderTraversal(root);

    return 0;
}