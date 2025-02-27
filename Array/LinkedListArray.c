#include <stdio.h>
#include <stdlib.h>

#define maxi 5

int index = 0;
int head = -1;

int data[maxi];
int next[maxi];

// Function to insert a value into the list
void insert(int value) {
    if (index == maxi) {
        printf("List is full, cannot insert.\n");
        return;
    }

    // Insert value in the 'data' array at the current index
    data[index] = value;

    // If the list is empty (head == -1), set the head to the current index
    if (head == -1) {
        head = index;
        next[index] = -1;  // Last element in the list points to -1
    }
    else {
        // Find the last element (where next[temp] == -1)
        int temp = head;
        while (next[temp] != -1) {
            temp = next[temp];
        }

        // Set the next pointer of the last element to the current index
        next[temp] = index;
        next[index] = -1;  // Current element points to -1 (last element)
    }

    index++;  // Increment index to track the next available slot
}

// Function to display the current list
void display() {
    if (head == -1) {
        printf("List is empty.\n");
        return;
    }

    // Traverse the list from head to end
    int temp = head;
    while (temp != -1) {
        printf("%d -> ", data[temp]);
        temp = next[temp];
    }
    printf("NULL\n");  // End of list
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    // Display the list after insertions
    display();  // Output: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    insert(60);  // Attempting to insert when the list is full

    return 0;
}
