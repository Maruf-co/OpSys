#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int i;
    for(i = 0; i < 3; ++i){
        fork();
    }
    sleep(60);
}

