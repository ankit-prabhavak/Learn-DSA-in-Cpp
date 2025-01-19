#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100  // Maximum number of non-zero terms

// Structure to store a non-zero term in the sparse matrix
typedef struct {
    int row;
    int col;
    int value;
} SparseTerm;

// Function to multiply two sparse matrices
void multiplySparseMatrices(SparseTerm *A, int aTerms, SparseTerm *B, int bTerms, SparseTerm *C, int *cTerms) {
    *cTerms = 0;  // Initialize count of non-zero terms in the result

    // Multiply the sparse matrices A and B
    for (int i = 0; i < aTerms; i++) {
        for (int j = 0; j < bTerms; j++) {
            // If the column of A matches the row of B, multiply the values
            if (A[i].col == B[j].row) {
                int row = A[i].row;
                int col = B[j].col;
                int value = A[i].value * B[j].value;

                // Check if the result term already exists
                int found = 0;
                for (int k = 0; k < *cTerms; k++) {
                    if (C[k].row == row && C[k].col == col) {
                        C[k].value += value;  // Add to existing term
                        found = 1;
                        break;
                    }
                }

                // If it doesn't exist, add it as a new term
                if (!found && *cTerms < MAX_TERMS) {
                    C[*cTerms].row = row;
                    C[*cTerms].col = col;
                    C[*cTerms].value = value;
                    (*cTerms)++;
                }
            }
        }
    }
}

// Function to print the sparse matrix
void printSparseMatrix(SparseTerm *matrix, int terms) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < terms; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    SparseTerm A[MAX_TERMS] = {
        {0, 0, 5},
        {0, 2, 8},
        {1, 1, 6}
    };
    int aTerms = 3;  // Number of non-zero terms in A

    SparseTerm B[MAX_TERMS] = {
        {0, 1, 4},
        {2, 0, 7},
        {2, 2, 2}
    };
    int bTerms = 3;  // Number of non-zero terms in B

    SparseTerm C[MAX_TERMS];  // Result matrix
    int cTerms;  // Number of non-zero terms in C

    // Multiply A and B
    multiplySparseMatrices(A, aTerms, B, bTerms, C, &cTerms);

    // Print the result
    printf("Resultant Sparse Matrix:\n");
    printSparseMatrix(C, cTerms);

    return 0;
}
