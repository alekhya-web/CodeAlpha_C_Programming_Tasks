#include <stdio.h>

#define MAX 10

void inputMatrix(int mat[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%6d", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void getDimensions(const char *name, int *rows, int *cols) {
    do {
        printf("Enter rows and columns for %s (1-%d): ", name, MAX);
        if (scanf("%d %d", rows, cols) != 2 || *rows < 1 || *rows > MAX || *cols < 1 || *cols > MAX) {
            printf("Invalid input! Both dimensions must be between 1 and %d.\n", MAX);
            while (getchar() != '\n');
            *rows = 0;
            *cols = 0;
        }
    } while (*rows < 1 || *rows > MAX || *cols < 1 || *cols > MAX);
}

int main() {
    int choice;
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    do {
        printf("\n=============================\n");
        printf("      Matrix Operations      \n");
        printf("=============================\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                do {
                    getDimensions("Matrix A", &r1, &c1);
                    getDimensions("Matrix B", &r2, &c2);
                    if (r1 != r2 || c1 != c2) {
                        printf("\nError: Matrix addition requires identical dimensions (%dx%d != %dx%d). Try again.\n\n", r1, c1, r2, c2);
                    }
                } while (r1 != r2 || c1 != c2);

                printf("\nEnter elements of Matrix A:\n");
                inputMatrix(a, r1, c1);

                printf("\nEnter elements of Matrix B:\n");
                inputMatrix(b, r2, c2);

                addMatrices(a, b, result, r1, c1);

                printf("\nMatrix A:\n");
                displayMatrix(a, r1, c1);
                printf("\nMatrix B:\n");
                displayMatrix(b, r2, c2);
                printf("\nSum Matrix:\n");
                displayMatrix(result, r1, c1);
                break;

            case 2:
                do {
                    getDimensions("Matrix A", &r1, &c1);
                    getDimensions("Matrix B", &r2, &c2);
                    if (c1 != r2) {
                        printf("\nError: Columns of Matrix A (%d) must equal rows of Matrix B (%d) for multiplication. Try again.\n\n", c1, r2);
                    }
                } while (c1 != r2);

                printf("\nEnter elements of Matrix A:\n");
                inputMatrix(a, r1, c1);

                printf("\nEnter elements of Matrix B:\n");
                inputMatrix(b, r2, c2);

                multiplyMatrices(a, b, result, r1, c1, c2);

                printf("\nMatrix A:\n");
                displayMatrix(a, r1, c1);
                printf("\nMatrix B:\n");
                displayMatrix(b, r2, c2);
                printf("\nProduct Matrix (%dx%d):\n", r1, c2);
                displayMatrix(result, r1, c2);
                break;

            case 3:
                getDimensions("Matrix", &r1, &c1);

                printf("\nEnter elements of Matrix:\n");
                inputMatrix(a, r1, c1);

                transposeMatrix(a, result, r1, c1);

                printf("\nOriginal Matrix (%dx%d):\n", r1, c1);
                displayMatrix(a, r1, c1);
                printf("\nTransposed Matrix (%dx%d):\n", c1, r1);
                displayMatrix(result, c1, r1);
                break;

            case 4:
                printf("\nExiting Matrix Operations program. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option! Please select between 1 and 4.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}
