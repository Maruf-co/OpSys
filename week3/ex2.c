#include <stdio.h>

void bubble_sort(int a[], int n) {
    int i = 0, j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                a[j] = a[j] + a[j+1];
                a[j+1] = a[j] - a[j+1];
                a[j] = a[j] - a[j+1];
            }
        }
    }
}

int main(){
    int a[10];
    int i;
    printf("Array before Bubble Sort\n");
    for(i = 0; i < 10; ++i){
        a[i] = 10-i;
        printf("%d ", a[i]);
    }
    printf("\nArray after sorting\n");
    bubble_sort(a, 10);
    for(i = 0; i < 10; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
