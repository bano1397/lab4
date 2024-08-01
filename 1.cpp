#include<iostream>
using namespace std;

class Node{
 private:
 int data;
 Node* Next;
 Node* Previous;

 public:
 Node() : data(0), Next(NULL), Previous(NULL) {}

 int GetData(){
     return data;
 }

 void SetData(int data){
     this->data = data;
 }

 Node* GetNext(){
     return Next;
 }

 void SetNext(Node* nextNode){
     this->Next = nextNode;
 }

 Node* GetPrevious (){
     return Previous;
 }

 void SetPrevious(Node* prevNode){
     this->Previous = prevNode;
 }
};

class DoublyList {
private:
    Node* CurrentLocation;

public:
    DoublyList() {
        CurrentLocation = NULL;
    }

    void InsertNode(int data) {
        Node* newNode = new Node();
        newNode->SetData(data);
        newNode->SetNext(NULL); 
        newNode->SetPrevious(NULL); 

        if (CurrentLocation == NULL) {
            CurrentLocation = newNode; 
        } else {
            Node* temp = CurrentLocation;
            while (temp->GetNext() != NULL) { 
                temp = temp->GetNext();
            }
            temp->SetNext(newNode); 
            newNode->SetPrevious(temp); 
        }
    }

    void DeleteNode(int data) {
        Node* temp = CurrentLocation;

        if (temp == NULL) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }
        
        while (temp != NULL && temp->GetData() != data) {
            temp = temp->GetNext();
        }

        if (temp == NULL) {
            cout << "Node not found." << endl;
            return;
        }

        if (temp == CurrentLocation) {
            CurrentLocation = temp->GetNext();
            if (CurrentLocation != NULL) {
                CurrentLocation->SetPrevious(NULL);
            }
        } else { 
            Node* prev = temp->GetPrevious();
            Node* next = temp->GetNext();
            prev->SetNext(next);
            if (next != NULL) {
                next->SetPrevious(prev);
            }
        }

        delete temp; 
    }

    void PrintList() {
        Node* temp = CurrentLocation;

        cout << "NULL->";
        if (temp == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->GetData() << "->";
            temp = temp->GetNext();
        }

        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList DL;

    DL.InsertNode(2);
    DL.InsertNode(8);
    DL.InsertNode(9);
    DL.InsertNode(15);

    DL.PrintList(); 

    cout << "\nInsert node 19" << endl;
    DL.InsertNode(19); 
    
    DL.PrintList(); 

    cout << "\nDelete node 9" << endl;
    DL.DeleteNode(9);
    
    DL.PrintList(); 

    cout << "\nDelete a node not present in the list" << endl;
    DL.DeleteNode(100);

    DL.PrintList(); 

    return 0;
}



