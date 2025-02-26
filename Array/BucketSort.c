#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

// Function to perform insertion sort on each bucket
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to implement bucket sort
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    int i, j;
    int bucketIndex;
    int bucketSize = 10; // Can be adjusted

    // Create an array of buckets
    int **buckets = (int **)malloc(BUCKET_COUNT * sizeof(int *));
    int *bucketSizes = (int *)malloc(BUCKET_COUNT * sizeof(int));
    
    for (i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = (int *)malloc(bucketSize * sizeof(int));
        bucketSizes[i] = 0;
    }

    // Distribute input array values into buckets
    for (i = 0; i < n; i++) {
        bucketIndex = (int)(arr[i] * BUCKET_COUNT); // Index in bucket
        if (bucketSizes[bucketIndex] < bucketSize) {
            buckets[bucketIndex][bucketSizes[bucketIndex]++] = (int)(arr[i] * 100);  // Scaling to an integer for ease of use
        }
    }

    // Sort individual buckets using insertion sort
    for (i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Collect the sorted elements into the original array
    int index = 0;
    for (i = 0; i < BUCKET_COUNT; i++) {
        for (j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = (float)buckets[i][j] / 100.0f;  // Convert back to float
        }
    }

    // Free memory for the buckets
    for (i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print an array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 10;
    float arr[] = {0.42, 0.32, 0.35, 0.15, 0.6, 0.58, 0.49, 0.37, 0.29, 0.17};

    printf("Original array: \n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
