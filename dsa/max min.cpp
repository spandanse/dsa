#include <stdio.h>

#define MAX_SIZE 10

// Function to find the maximum value in a matrix
int findMaxValue(int mat[][MAX_SIZE], int rows, int cols) {
    int maxVal = mat[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] > maxVal) {
                maxVal = mat[i][j];
            }
        }
    }
    return maxVal;
}

// Function to find the minimum value in a matrix
int findMinValue(int mat[][MAX_SIZE], int rows, int cols) {
    int minVal = mat[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] < minVal) {
                minVal = mat[i][j];
            }
        }
    }
    return minVal;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    // Input for the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Find maximum and minimum values
    int maxVal = findMaxValue(matrix, rows, cols);
    int minVal = findMinValue(matrix, rows, cols);

    // Display maximum and minimum values
    printf("Maximum value in the matrix: %d\n", maxVal);
    printf("Minimum value in the matrix: %d\n", minVal);

    return 0;
}

