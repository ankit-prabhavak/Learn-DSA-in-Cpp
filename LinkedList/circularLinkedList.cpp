#include <iostream>

using namespace std;



class Node{
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }

};


class CircularLinkedList {
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head; // Point tail to head to make it circular
        } else {
            newNode->next = head;
            tail->next = newNode; // Point tail to new node
            head = newNode; // Update head to new node
        }
    }

    void deleteAtBeginning() {
        if (head == nullptr) return; // List is empty

        Node* temp = head;
        if (head == tail) { // Only one node in the list
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            tail->next = head; // Update tail's next to new head
        }
        temp->next = nullptr; // Disconnect the old head
        delete temp; // Free memory of the old head
    }
    
    void deleteAtEnd() {
        if (head == nullptr) return; // List is empty

        if (head == tail) { // Only one node in the list
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next; // Traverse to the second last node
            }
            delete tail; // Delete the last node
            tail = temp; // Update tail to the second last node
            tail->next = head; // Point tail's next to head to maintain circularity
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head; // Point tail to head to make it circular
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Point tail to head to make it circular
        }
    }

    void display() {
        if (head == nullptr) return;

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


int main() {
    CircularLinkedList cll;
    cll.insertAtBeginning(10);
    cll.insertAtBeginning(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cll.display(); // Output: 20 10 30 40

    cll.deleteAtBeginning();
    cll.deleteAtEnd();
    cll.display(); // Output: 10 30

    

    return 0;
}