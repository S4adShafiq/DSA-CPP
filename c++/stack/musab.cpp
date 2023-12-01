#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

int arr[MAX_SIZE];
int top = -1;

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == MAX_SIZE - 1;
}

int size()
{
    return top + 1;
}

void push(int value)
{
    if (isFull())
    {
        cout << "Stack overflow, cannot push more elements." << endl;
    }
    arr[++top] = value;
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow, cannot pop from an empty stack." << endl;
        return -1;
    }
    return arr[top--];
}

int peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty, cannot peek." << endl;
        return -1;
    }
    return arr[top];
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
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            push(c);
        else if (c == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix += peek();
                pop();
            }
            pop();
        }
        else
        {
            while (!isEmpty() && getPrecedence(c) <= getPrecedence(peek()))
            {
                postfix += peek();
                pop();
            }
            push(c);
        }
    }

    while (!isEmpty())
    {
        postfix += peek();
        pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix)
{
    for (char c : postfix)
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
            int operand2 = pop();
            int operand1 = pop();
            switch (c)
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                if (operand2 != 0)
                {
                    push(operand1 / operand2);
                }
                else
                {
                    cout << "Error: Division by zero." << endl;
                    return 0;
                }
                break;
                
            default:
                cout << "Error: Invalid operator." << endl;
                return 0;
            }
        }
    }
    return pop();
}

int main()
{
    int op = -1, result;
    string infixExpression;
    string postfixExpression;

    while (op != 0)
    {

        cout << "\nEnter 1 to Push\nEnter 2 to Pop\nEnter 3 to Peek\nEnter 4 to Convert Infix Expression to Postfix Expression\nEnter 5 to Evalute Postfix Expression\nEnter 0 to Exit\n\nEnter: ";
        cin >> op;

        switch (op)
        {
        case 1:
            int element;
            cout << "\nEnter value to Push: ";
            cin >> element;
            cout << endl;
            push(element);
            break;

        case 2:
            cout << "\nPopped: " << pop() << endl;
            break;

        case 3:
            cout << "\nTop Value: " << peek() << endl;
            break;

        case 4:
            cout << "Enter an infix expression: ";
            cin.ignore();
            getline(cin, infixExpression);

            postfixExpression = infixToPostfix(infixExpression);
            cout << "Postfix expression: " << postfixExpression << endl;
            break;

        case 5:
            cout << "Enter a postfix expression: ";
            cin.ignore();
            getline(cin, postfixExpression);

            result = evaluatePostfix(postfixExpression);
            cout << "Result: " << result << endl;
            break;

        default:
            cout << "\nInvalid option. Please try again." << endl;
            break;
        }
    }
    return 0;
}