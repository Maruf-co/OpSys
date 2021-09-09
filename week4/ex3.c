#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    char c[100];
    printf("Write your commands: (command size is 100 characters)\nWrite 'stop' if you want to finish\n");
    while(1){
        printf(">");
        scanf("%s", &c);
        if(!strcmp(c, "stop")){
            printf("Exit command are made. Goodbye!\n");
            break;
        }
        system(c);
    }
}

