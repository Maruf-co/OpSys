#include <stdio.h>


int check(int A[], int R[], int n){
    for(int i = 0; i < n; ++i){
        if(A[i] < R[i]){
            return 0;
        }
    }
    return 1;
}

int main() {
    // Input
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    int rows, cols; // rows = 5, cols = 3
    fscanf(in, "%d%d", &rows, &cols);
    int E[cols], A[cols], unmarked[rows];
    for (int i = 0; i < cols; ++i) {
        fscanf(in, "%d", &E[i]);
    }
    for (int i = 0; i < cols; ++i) {
        fscanf(in, "%d", &A[i]);
    }
    int C[rows][cols], R[rows][cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fscanf(in, "%d", &C[i][j]);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fscanf(in, "%d", &R[i][j]);
        }
        unmarked[i] = 1;
    }
    // Algorithm
    int flag;
    for(int i = 0; i < rows; ++i){
        flag = 1;
        for(int j = 0; j < rows; ++j){
            if(unmarked[j] == 1 && check(A, R[j], cols) == 1){
                flag = 0;
                unmarked[j] = 0;
                for(int k = 0; k < cols; ++k){
                    A[k] += C[i][k];
                }
            }
        }
        int sum = 0;
        for(int j = 0; j < rows; ++j){
            sum += unmarked[j];
        }
        if(sum == 0){
            break;
        }
        if(flag == 1){
            fprintf(out, "Deadlock detected!\n");
            fprintf(out, "Number of deadlocked processes: %d\n", sum);
            return 0;
        }
    }

    for(int i = 0; i < cols; ++i){
        fprintf(out, "A[%d] = %d ", i, A[i]);
    }
    fprintf(out, "\n");
    fprintf(out, "No deadlock is detected\n");
    fclose(in);
    fclose(out);
    return 0;
}