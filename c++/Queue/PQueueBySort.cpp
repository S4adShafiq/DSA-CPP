#include <bits/stdc++.h>
using namespace std;

struct datainfo
{
    int data;
    int priority;
};

void enqueue(vector<datainfo> &q)
{   
    datainfo n;
    cout<<"Enter value\n";
    cin>>n.data;
    
    cout<<"Enter its Priority\n";
    cin>>n.priority;
    while(n.priority==0)
    {
        cout<<"PRIORITY INALID\n";
        cin>>n.priority;
    }

    q.push_back(n);
}

void dequeue(vector<datainfo> &q)
{
    q.erase(q.begin());
}

void display(vector<datainfo> &q)
{
    cout << "DATA\tPRIORITY\n";
    for (datainfo i : q)
    {
        cout << i.data << "\t" << i.priority << endl;
    }
}

datainfo sort(vector<datainfo> &q)
{
    int temp = 0;
    int temp2 = 0;
    for (int i = 0; i < q.size() - 1; i++)
    {   for (int j = i + 1; j < q.size(); j++)
        {
            if (q[i].priority > q[j].priority)
            {
                temp = q[i].priority;
                q[i].priority = q[j].priority;
                q[j].priority = temp;
                temp2 = q[i].data;
                q[i].data = q[j].data;
                q[j].data = temp2;
            }
        }
    }

}

int main()
{

    int choice;
    vector<datainfo> queue;
    do
    {
        cout << "\n |Enter 1 to Enter Data|\t|Enter 2 to Dequeue|\t|Enter 3 to Display|\t|Enter 4 to Sort according to priority|\t|Enter 0 to Exit|";
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue(queue);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            sort(queue);
            break;
        case 0:
            cout << "|THE END|";
            break;
        default:
            cout << "\n |INVALID OPTION|" << endl;
        }
    } while (choice != 0);
    return 0;
    
}