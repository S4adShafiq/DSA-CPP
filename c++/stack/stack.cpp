#include <bits/stdc++.h>
using namespace std;
const int limit = 100;
int top = -1;
int a[limit];
bool isEmpty()
{
    return top == -1;
}
bool isFull()
{
    return top == limit - 1;
}
void push(int n)
{
    if (isFull())
    {
        cout << "Stack is full" << endl;
    }
    a[++top] = n;
}
int pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty " << endl;
        return -1;
    }
    return a[top--];
}
int peek()
{
    if (isEmpty())
    {
        cout << "Stack is Empty " << endl;
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
        cout << "Press 1 to Push\nPress 2 to Pop\nPress 3 to Peek\nPress 4 to Exit" << endl;
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
                push(v);
            }
            break;
        case 2:
            system("cls");
            cout << "Poped Value is :" << pop() << endl;
            break;
        case 3:
            cout << "Peeked Value is : " << peek() << endl;
            break;
        default:
            break;
        }
    }
}
