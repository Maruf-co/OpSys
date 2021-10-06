#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
    int i;
    for(i = 0; i < 10; ++i){
        int N = 100*1024*1024;
        char* arr = (char*)malloc(N);
        memset(arr, 0, N);

        int who = RUSAGE_SELF;
        struct rusage u;
        int r = getrusage(who, &u);
        printf("Memory usage: %d\n", u.ru_maxrss);

        sleep(1);

        free(arr); // If we won't free memory, then program will show how our memory accumulate during completion
    }
}
