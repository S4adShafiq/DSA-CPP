#include <bits/stdc++.h>
using namespace std;
const int limit = 100;
int top = -1;
int rear = -1;
int a[limit];
bool isEmpty()
{
    return top == -1;
}
bool isFull()
{
    return top == limit - 1;
}
void enqueue(int n)
{
    if (isFull())
    {
        cout << "Queue is full" << endl;
    }
    if (top == -1)
    {
        top = 0;
    }
    a[++rear] = n;
}
void dequeue()
{

    if (isEmpty())
    {
        cout << "Queue is Empty " << endl;
    }
    top++;
}
int peek()
{
    if (isEmpty())
    {
        cout << "Queue is Empty " << endl;
        return -1;
    }
    return a[top];
}

int main()
{
    int n, v, opt;
    while (opt != 4)
    {
        cout << endl;
        cout << "Press 1 to Enqueue\nPress 2 to Dequeue\nPress 3 to Peek\nPress 4 to Exit" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "How many Value want to put : " << endl;
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                cout << "Enter the Value : ";
                cin >> v;
                enqueue(v);
            }
            break;
        case 2:
            system("cls");
            dequeue();
            break;
        case 3:
            cout << "Peeked Value is : " << peek() << endl;
            break;
        default:
            break;
        }
    }
}
