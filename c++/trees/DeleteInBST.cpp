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
Node * DeletionInBST(Node * root ,int data){
    if (root == NULL){
        return root;
    }
    if(root->data==data){
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL&&root->right==NULL){
            Node * temp =root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL&&root->right!=NULL){
            Node * temp =root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL&&root->right!=NULL){
            int min= Min(root->right)->data;
            root->data=min;
            root->right=DeletionInBST(root->right,min);
            return root;
        }
    }
    else if (root->data>data){
        root->left= DeletionInBST(root->left,data);
        return root;
    }
    else{
        root->right= DeletionInBST(root->right,data);
        return root;
    }
}

int main(){
    int s;
    Node * root= NULL;
    cout<<"Enter To create BST"<<endl;
    InsertData(root);
    cout<<"Printing the BST"<<endl;
    LevelOrderTraversal(root);
    cout <<"Enter A value to Search: ";
    cin>>s;
    DeletionInBST(root,s);
    cout<<"After Deletion : "<<endl;
    LevelOrderTraversal(root);
    return 0;
}