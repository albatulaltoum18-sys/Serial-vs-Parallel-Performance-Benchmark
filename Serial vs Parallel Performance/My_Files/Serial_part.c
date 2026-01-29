#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500

double A[N][N], B[N][N], C[N][N];

int main() {
   
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = 2;
            B[i][j] = 2;
            C[i][j] = 0;
        }

    clock_t start = clock();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];

    double sum = 0.0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += C[i][j];

    printf("Sum of all elements in C = %.2f\n", sum);

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Serial execution time: %.3f seconds\n", time_taken);

    return 0;
}