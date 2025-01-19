#include <stdio.h>

void arrayRepresentation(int sparseMatrix[3][3]) {
    printf("Triplet Representation:\n");
    printf("Row  Col  Value\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sparseMatrix[i][j] != 0) {
                printf("%d    %d    %d\n", i, j, sparseMatrix[i][j]);
            }
        }
    }
}

int main() {
    int sparseMatrix[3][3] = {
        {0, 0, 3},
        {0, 4, 0},
        {5, 0, 0}
    };
    arrayRepresentation(sparseMatrix);
    return 0;
}