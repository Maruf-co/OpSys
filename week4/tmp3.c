#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    printf("Write your commands: (command size is 200 characters)\nWrite 'ctrl+C' if you want to finish\n");
    while(1){
        char c[200];
        printf(">");
        fgets(c, 200, stdin);

        char* argv = strtok(c, " ");
        if(fork() == 0){
            execvp(argv[0], argv);
        }else{
            system(c);
        }
    }
}

