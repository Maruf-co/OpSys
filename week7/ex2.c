#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the size of your array N: ");
    scanf("%d", &n);
    int* arr = malloc(n*sizeof(int));
    int i;
    for(i = 0; i < n; ++i){
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");
    arr = realloc(arr, 0);
}
