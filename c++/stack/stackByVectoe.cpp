#include <bits/stdc++.h>
using namespace std;

void push(vector<int> &q,int n){
    q.push_back(n);
}
void pop(vector<int> &q){
    cout<<q.back();
    q.pop_back();
}
void peek(vector<int> &q){
    cout<<q.back();
}
void printStack(vector<int> &q){
    for(int i:q){
        cout<<i<<" ";
    }
}

int main(){
    vector<int> q;
    int n;
    push(q,2);
    push(q,7);
    push(q,3);
    push(q,9);

    cout <<"Printing Stack: ";
    printStack(q);
    cout <<"\nPoped Value: ";
    pop(q);
    cout <<"\nPeeked Value: ";
    peek(q);
}