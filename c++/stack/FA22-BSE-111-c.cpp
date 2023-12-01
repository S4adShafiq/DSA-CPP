#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data), next(NULL) {}
};

Node *head = NULL;

bool isEmpty()
{
    return head == NULL;
}

void display()
{
    if (!isEmpty())
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << "   ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Stack is empty.\n";
    }
}

void push(int value)
{
    Node *ptr = new Node(value);
    ptr->next = head;
    head = ptr;
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty. Cannot pop." << endl;
        return -1;
    }

    int poppedValue = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    return poppedValue;
}

int peek()
{
    if (!isEmpty())
    {
        return head->data;
    }
    else
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
}

int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string infix)
{
    while (!isEmpty())
    {
        pop();
    }

    string postfix = "";
    string currentNumber = "";

    for (char c : infix)
    {
        if (isdigit(c))
        {
            currentNumber += c;
        }
        else
        {
            if (!currentNumber.empty())
            {
                postfix += currentNumber + " ";
                currentNumber = "";
            }

            if (c == ' ')
            {
                continue;
            }
            else if (c == '(')
            {
                push(c);
            }
            else if (c == ')')
            {
                while (!isEmpty() && peek() != '(')
                {
                    postfix += peek();
                    postfix += " ";
                    pop();
                }
                pop();
            }
            else
            {
                while (!isEmpty() && getPrecedence(c) <= getPrecedence(peek()))
                {
                    postfix += peek();
                    postfix += " ";
                    pop();
                }
                 push(c);
            }
        }
    }
    if (!currentNumber.empty())
    {
        postfix += currentNumber + " ";
    }

    while (!isEmpty())
    {
        postfix += peek();
        postfix += " ";
        pop();
    }

    return postfix;
}

int main()
{
    system("cls");
    int choice;
    string infixExpression, postfixExpression;
    int result;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            system("cls");

            cout << "Enter an infix expression: ";
            cin.ignore();
            getline(cin, infixExpression);

            postfixExpression = infixToPostfix(infixExpression);
            cout << "Postfix expression: " << postfixExpression << endl;

        case 0:
        {
            return 0;
        }

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
            system("cls");
            display();
        }

        return 0;
    }
}