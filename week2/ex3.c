#include <stdio.h>
int main(int argc, char *argv[]){
    int n;
    if(argc > 1){
	sscanf(argv[1], "%d", &n);
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n-i; ++j){
            printf(" ");
        }
        for(int j = 0; j < i; ++j){
            printf("* ");
        }
	printf("\n");
    }
    printf("\n");

    return 0;
}

