#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

struct circularList {
  int length;
  Node *head;
};

void ins(circularList *list, int data) {
  Node *ptr = list->head;
  while (ptr != NULL && ptr->data != data) {
    ptr = ptr->next;
  }

  if (ptr == NULL) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->length++;
  }
}

void del(circularList *list, int key) {
  Node *current = list->head;
  Node *previous = NULL;
  while (current != NULL && current->data != key) {
    previous = current;
    current = current->next;
  }

  if (current != NULL) {
    if (current == list->head) {
      list->head = list->head->next;
    } else {
      previous->next = current->next;
    }

    delete current;
    list->length--;
  }
}

void ist(circularList *list, int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
  list->length++;
}

void dst(circularList *list) {
  if (list->head == NULL) {
    return;
  }
  Node *nodeToDelete = list->head;
  list->head = list->head->next;
  delete nodeToDelete;
  list->length--;
}

void prt(circularList *list) {
  Node *current = list->head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }

  cout << endl;
}

Node *fndkey(circularList *list, int key) {
  Node *current = list->head;
  while (current != NULL && current->data != key) {
    current = current->next;
  }
  return current;
}
int main() {
  circularList *list = new circularList();
  list->head = NULL;
  list->length = 0;
  ins(list, 10);
  ins(list, 20);
  ins(list, 30);
  prt(list);
  del(list, 20);
  prt(list);
  Node *node = fndkey(list, 30);
  if (node != NULL) {
    cout << "The node containing the key 30 has data " << node->data << "." << endl;
  }
}
