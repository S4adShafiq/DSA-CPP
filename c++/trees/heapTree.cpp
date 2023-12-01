#include <bits/stdc++.h>
using namespace std;
struct heap
{
    int arr[100];
    int size;
    heap(){
        size=0;
    }
    void insert(int data){          
        size+=1;
        int index= size;
        arr[index]=data;
        while (index > 1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index= parent;
            }
            else return;
        }
    }
    void display(){
        for(int n=1;n<=size;n++){
            cout<< arr[n] <<" ";
        }
    }
};


int main(){
    heap h;
    int n;
    while(true){
        cout <<"Enter the Values :"<<endl;
        cin>>n;
        if(n==-1){
            break;
        }
        h.insert(n);
    }

    h.display();
    return 0;
}