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
        scanf("%[^\n]%*c", c);

        char* argv[200];
        int pos = 0;
        argv[pos] = strtok(c, " ");
        while(argv[pos] != NULL){
            ++pos;
            argv[pos] = strtok(NULL, " ");

        }

        pid_t x = fork();

        if(x == 0){
            execvp(argv[0], argv);
        }else{
            wait(NULL);
        }

    }
}

