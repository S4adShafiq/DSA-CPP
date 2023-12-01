#include <bits/stdc++.h>
using namespace std;

void enqueue(vector<int> &q,int n){
    q.push_back(n);
}
void dequeue(vector<int> &q){
    cout<<*q.begin();
    q.erase(q.begin());
}
void peek(vector<int> &q){
    cout<<q[0];
}
void printQueue(vector<int> &q){
    for(int i:q){
        cout<<i<<" ";
    }
}
int priority(vector<int> &q){
    sort(q.begin(),q.end());
    return *q.begin();
}

int main(){
    vector<int> q;
    int n;
    enqueue(q,2);
    enqueue(q,7);
    enqueue(q,3);
    enqueue(q,9);

    cout <<"Printing Queue: ";
    printQueue(q);
    cout <<"\nDequeued Value: ";
    dequeue(q);
    cout <<"\nPeeked Value: ";
    peek(q);
    cout <<"\nPriority Peeked Value: "<<priority(q);
}