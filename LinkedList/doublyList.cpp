#include <iostream>

using namespace std;


class Node {
public:
      int data;
      Node* next;
      Node* prev; // Pointer to the previous node

      Node(int val) {
        data = val;
        next = NULL;
        prev = NULL; // Initialize the previous pointer to NULL
      }
};


class DoublyList {
    Node* head;
    Node* tail;
public:
      DoublyList() {
        head = tail = NULL;
      }

      void push_front(int val) {
        Node* newNode = new Node(val); // Dynamic
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode; // Set the previous pointer of the old head
            head = newNode;
        }
      }

      void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail; // Set the previous pointer of the new node
            tail = newNode;
        }
      }

        void pop_front(){
            if(head == NULL){
                cout << "Linked List is empty" << endl;
                return;
            }
            Node* temp = head;
            head  = head->next;
            if (head != NULL) {
                head->prev = NULL; // Set the previous pointer of the new head to NULL
            } else {
                tail = NULL; // If the list is now empty, set tail to NULL
            }
            temp->next = NULL;
    
            delete temp;
        }

        void pop_back(){
            if(head == NULL){
                cout << "Linked List is empty" <<endl;
                return;
            }
            Node* temp = tail;
            tail = tail->prev; // Move the tail pointer to the previous node
            if (tail != NULL) {
                tail->next = NULL; // Set the next pointer of the new tail to NULL
            } else {
                head = NULL; // If the list is now empty, set head to NULL
            }
            temp->prev = NULL;
    
            delete temp;
        }

        void insert(int val, int pos){
            if(pos < 0){
                cout << "Invalid position" << endl;
                return;
            }

            if(pos == 0){
                push_front(val);
                return;
            }

            Node* temp = head;
            for(int i = 0; i < pos-1; i++) {
                if(temp == NULL) {
                    cout << "Invalid position" << endl;
                    return;
                }
                temp = temp->next;
            }
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            newNode->prev = temp; // Set the previous pointer of the new node
            if (temp->next != NULL) {
                temp->next->prev = newNode; // Set the previous pointer of the next node
            } else {
                tail = newNode; // If inserting at the end, update tail
            }
            temp->next = newNode;
        }

        int search(int key) {
            if(head == NULL){
                cout << "Linked List is empty" <<endl;
                return -1;
            }

            Node* temp = head;
            int idx = 0;

            while(temp != NULL) {
                if(temp->data == key){
                    return idx;
                }

                temp = temp->next;
                idx++;
            }

            return -1;
        }

        void display() {
            if(head == NULL){
                cout << "Linked List is empty" <<endl;
                return;
            }
            Node* temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void display_reverse() {
            if(tail == NULL){
                cout << "Linked List is empty" <<endl;
                return;
            }
            Node* temp = tail;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
        }

        void clear() {
            Node* current = head;
            while (current != NULL) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = tail = NULL; // Set both head and tail to NULL after clearing the list
        }

        ~DoublyList() {
            clear(); // Call the clear function to free memory
        }
};


int main() {
    DoublyList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.display(); // Output: 0 1 2 3
    list.display_reverse(); // Output: 3 2 1 0
    cout << "Position of 2: " << list.search(2) << endl; // Output: Position of 2: 2
    list.insert(4, 2); // Insert 4 at position 2
    list.display(); // Output: 0 1 4 2 3
    list.pop_front();
    list.display(); // Output: 1 4 2 3
    list.pop_back();
    list.display(); // Output: 1 4 2

    return 0;
}

