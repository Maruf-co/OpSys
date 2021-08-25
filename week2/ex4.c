#include <stdio.h>

void mySwap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
int main(){
    int a, b;
    printf("Write value of a - ");
    scanf("%d", &a);
    printf("Write value of b - ");
    scanf("%d", &b);
    mySwap(&a, &b);
    printf("After swapping\na = %d \nb = %d\n", a, b);

}

