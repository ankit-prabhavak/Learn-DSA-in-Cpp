#include <iostream>

using namespace std;




// Implementation of Circular Queue
class CircularQueue {
    int* arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = size = 0;
        rear = - 1;
    }

    void push(int x) {
        if (size == capacity) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int getFront() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int getSize() {
        return size;
    }


};


// Driver code
int main() {
    CircularQueue cq(5);

    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);




    cout << "Front element: " << cq.getFront() << endl;
    cout << "Rear element: " << cq.getRear() << endl;
    cout << "Queue size: " << cq.getSize() << endl;
    cq.pop();
    cout << "Front element after pop: " << cq.getFront() << endl;
    cq.push(60);
    cout << "Rear element after pushing 60: " << cq.getRear() << endl;

    while (!cq.isEmpty())
    {
        /* code */
        cout << "Popping element: " << cq.getFront() << endl;
        cq.pop();
    }
    

    return 0;
}