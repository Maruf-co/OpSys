#include <stdio.h>

int main(){
    
    printf("Hello world!\n");
    
    char s[10];
    puts("Enter a string --> ");
    fgets(s, 100, stdin);
    
    printf("My string is %s \n", s);
    
    return 0;
}


