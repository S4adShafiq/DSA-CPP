#include <iostream>
using namespace std;

struct NodeT {
    int data;
    NodeT* next;
};

struct CircularList {
    int length;
    NodeT* current;

    CircularList() : length(0), current(nullptr) {}

    void ins(int data) {
       
        if (length == 0) {
            current = new NodeT{data, nullptr};
            current->next = current; 
            length++;
            return;
        }

        if (fnd(data)) {
            cout << "Data already exists in the list." << endl;
            return;
        }

        NodeT* newNode = new NodeT{data, nullptr};
        newNode->next = current->next;
        current->next = newNode;
        length++;
    }

    NodeT* fnd(int key) {
        if (length == 0) {
            cout << "List is empty." << endl;
            return nullptr;
        }

        NodeT* temp = current;
        do {
            temp = temp->next;
            if (temp->data == key) {
                current = temp;  
                return temp;
            }
        } while (temp != current);

        cout << "Key not found in the list." << endl;
        return nullptr;
    }

    void del(int key) {
        if (length == 0) {
            cout << "List is empty." << endl;
            return;
        }

        NodeT* prev = current;
        NodeT* temp = current;
        do {
            prev = temp;
            temp = temp->next;
            if (temp->data == key) {
                prev->next = temp->next;
                delete temp;
                length--;
                return;
            }
        } while (temp != current);
        cout << "Key not found in the list." << endl;
    }

    void icr(int data) {
        NodeT* newNode = new NodeT{data, nullptr};
        newNode->next = current->next;
        current->next = newNode;
        length++;
    }

    void dcr() {
        if (length == 0) {
            cout << "List is empty." << endl;
            return;
        }

        NodeT* temp = current;
        do {
            temp = temp->next;
        } while (temp->next != current);

        NodeT* toDelete = current;
        temp->next = current->next;
        current = temp;
        delete toDelete;
        length--;
    }

    void prt() {
        if (length == 0) {
            cout << "List is empty." << endl;
            return;
        }

        NodeT* temp = current;
        do {
            temp = temp->next;
            cout << temp->data << " ";
        } while (temp != current);
        cout << endl;
    }
};

int main() {
    CircularList list;
    list.ins(10);
    list.ins(20);
    list.ins(30);

    cout << "List contents: ";
    list.prt();

    list.icr(15);
    list.dcr();

    cout << "List contents after icr and dcr: ";
    list.prt();

    list.del(20);

    cout << "List contents after del(20): ";
    list.prt();

    NodeT* found = list.fnd(10);
    if (found) {
        cout << "Found node with key 10: " << found->data << endl;
    }
}
