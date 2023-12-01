#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char data) {
        {
        this->data=data;
        this->next=NULL;
    }
    }
};

Node *head = NULL;

bool isEmpty()
{
    return head == NULL;
}

void InsertAtHead(Node *&head,int data){
    Node *n= new Node(data);
    n->next=head;
    head=n;
}
void Push(char value){
    Node *n= new Node(value);
    Node *ptr=head;
    if(head==NULL){
       InsertAtHead(head,value);
        return;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=n;
    n->next=NULL;
}

char pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty. Cannot pop." << endl;
        return '\0';
    }
    Node *ptr=head;
    Node *prev=NULL;
    while(ptr->next!=NULL){
        prev=ptr;
        ptr=ptr->next;
    }

    char popVal = ptr->data;
    Node *todelete = ptr;
    prev->next=NULL;
    ptr = prev->next;
    delete todelete;
    return popVal;
}

string sanitizeString(string input)
{
    string sanitized;
    for (char c : input)
    {
        if (isalnum(c))
        {
            sanitized += tolower(c);
        }
    }
    return sanitized;
}

string reverseString(string input)
{
    for (char c : input)
    {
        Push(c);
    }

    string reversedString;

    while (!isEmpty())
    {
        char c = pop();
        reversedString += c;
    }

    return reversedString;
}

bool isPalindrome(string input)
{
    string sanitized = sanitizeString(input);
    string reversed = reverseString(sanitized);
    return sanitized == reversed;
}

int main()
{
    string userInput;
    char continueCheck;

    do
    {
        cout << "Enter a string to check for palindrome: ";
        getline(cin, userInput);


        if (isPalindrome(userInput))
        {
            cout << "The input is a palindrome." << endl;
        }
        else
        {
            cout << "The input is not a palindrome." << endl;
        }

        while (!isEmpty())
        {
            pop();
        }

        cout << "Do you want to continue (y/n)? ";
        cin >> continueCheck;
        cin.ignore();

    } while (tolower(continueCheck) == 'y');

    return 0;
}