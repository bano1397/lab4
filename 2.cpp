#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(NULL) {} 
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(NULL) {} 

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "The list is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


void solveJosephus(CircularLinkedList &list, int step) {
    Node* current = list.head;
    Node* prev = NULL; 
    while (current != NULL && current->next != current) {
        for (int i = 1; i < step; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        if (current == list.head) {
            list.head = current->next;
        }
        delete current;
        current = prev->next;
    }
    if (current != NULL) {
        cout << "The last remaining person is at position " << current->data << endl;
    }
}

int main() {
    CircularLinkedList CL;
    int n = 5; 
    int step = 3; 

    for (int i = 1; i <= n; i++) {
        CL.insert(i);
    }

    cout << "Initial circle: ";
    CL.display();

    solveJosephus(CL, step);

    return 0;
}

