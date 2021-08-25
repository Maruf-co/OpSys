#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    printf("Int - %d with size %d\nFloat - %f with size %d\nDouble - %lf with size %d\n", i, sizeof(i), f, sizeof(i), d, sizeof(d));
}
