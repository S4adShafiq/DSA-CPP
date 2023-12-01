#include <iostream>
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
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}
string InToPost(string inf)
{
    string post = "";

    for (char c : inf)
    {
        if (isalnum(c))
            post += c;
        else if (c == '(')
            push(c);
        else if (c == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                post += peek();
                pop();
            }
            pop();
        }
        else
        {
            while (!isEmpty() && getPrecedence(c) <= getPrecedence(peek()))
            {
                post += peek();
                pop();
            }
            push(c);
        }
    }

    while (!isEmpty())
    {
        post += peek();
        pop();
    }

    return post;
}
int evalpost(string post)
{
    for (char c : post)
    {
        if (isdigit(c))
        {
            push(c - '0');
        }
        else if (c == ' ')
        {
            continue;
        }
        else
        {
            int op2 = pop();
            int op1 = pop();
            switch (c)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                if (op2 != 0)
                {
                    push(op1 / op2);
                }
                else
                {
                    cout << "Error Division bt 0 is not possible." << endl;
                    return 0;
                }
                break;

            default:
                cout << "Invalid operator" << endl;
                return 0;
            }
        }
    }
    return pop();
}
int main()
{
    int n, v,result;
    int opt = -1;
    string inf;
    string post;
    while (opt != 0)
    {
        cout << endl;
        cout << "Press 1 to Push\nPress 2 to Pop\nPress 3 to Peek\nEnter 4 to Convert Infix Expression to post Expression\nPress 5 to Evaluate the PostFix Expression\nPress 0 to Exit" << endl;
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
        case 4:
            cout << "Enter the Infix Expression :";
            cin.ignore();
            getline(cin, inf);
            post = InToPost(inf);
            cout << "The Converted Expression is : " << post << endl;
            break;
        case 5:
            cout << "Enter the post Expression :";
            cin.ignore();
            getline(cin, post);
            result = evalpost(post);
            cout << "The Result is : " << result << endl;
            break;
        default:
            break;
        }
    }
}