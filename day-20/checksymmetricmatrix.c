#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int isSymmetric = 1;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("The matrix must be square (rows equal to columns) to be symmetric.\n");
        return 0;
    }

    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    if (isSymmetric) {
        printf("The matrix is a symmetric matrix.\n");
    } else {
        printf("The matrix is not a symmetric matrix.\n");
    }

    return 0;
}
