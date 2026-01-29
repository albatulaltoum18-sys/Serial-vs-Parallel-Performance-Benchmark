#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 500
#define NUM_THREADS 4

double A[N][N], B[N][N], C[N][N];

void* multiply(void* arg) {
    int thread_id = *(int*)arg;
    int start = thread_id * (N / NUM_THREADS);
    int end = (thread_id + 1) * (N / NUM_THREADS);

    for (int i = start; i < end; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = 2;
            B[i][j] = 2;
            C[i][j] = 0;
        }

    clock_t start = clock();

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, multiply, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    double sum = 0.0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += C[i][j];

    printf("Sum of all elements in C = %.2f\n", sum);

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Parallel execution time: %.3f seconds\n", time_taken);

    return 0;
}