#include <stdio.h>
#include <time.h>

#define N 100

void multiplyMatrix(int mat1[][N], int mat2[][N], int result[][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[N][N], mat2[N][N], result[N][N];
    int size;

    printf("Enter the size of the matrices: ");
    scanf("%d", &size);

    printf("Enter the elements of first matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the elements of second matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    clock_t start_time = clock(); 
    multiplyMatrix(mat1, mat2, result, size);

    clock_t end_time = clock(); 

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; 

    printf("Resultant matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("Time taken: %lf seconds\n", time_taken);

    return 0;
}

