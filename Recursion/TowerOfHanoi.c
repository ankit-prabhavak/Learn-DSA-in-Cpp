#include <stdio.h>

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Base case: If there's only one disk, simply move it from source to destination
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    // Move top n-1 disks from source to auxiliary, so they are out of the way
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    
    // Take the number of disks as input
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Call the towerOfHanoi function to solve the problem
    printf("The sequence of moves to solve the Tower of Hanoi for %d disks is:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');  // A is source, B is auxiliary, C is destination
    
    return 0;
}
