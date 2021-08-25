
#include <stdio.h>
#define N 100
int main(){
    char str[N];
    printf("Write your string \n");
    scanf("%s", str);
    for(int i = 0; i < strlen(str); ++i){
        printf("%c", str[strlen(str)-i-1]);
    }
    printf("\n");

    return 0;
}

