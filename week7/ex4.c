#include <stdio.h>
#include <stdlib.h>

// function works for all types, but asks size of type (bytes)
void* myRealloc(void* arr, size_t newSize, size_t oldSize, int bytes){
    void* ans = NULL;
    if(arr == NULL){
        ans = malloc(newSize*sizeof(bytes));
    }else if(newSize == 0){
        free(arr);
    }else if(newSize > oldSize){
        ans = malloc(newSize*bytes);
        memcpy(ans, arr, oldSize*bytes);
        free(arr);
    }else{
        ans = arr;
    }
    return ans;
}


int main(){
    // Test of function by simple program, that asks to give 2 different sizes for an array
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

    int m;
    printf("Enter the new size of your array M: ");
    scanf("%d", &m);
    arr = myRealloc(arr, m, n, sizeof(int));
    for(i = 0; i < m; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
