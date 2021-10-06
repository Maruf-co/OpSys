#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    int i;
    for(i = 0; i < 10; ++i){
        int N = 10*1024*1024;
        char* arr = (char*)malloc(N);
        memset(arr, 0, N);
        sleep(1); // ex2: fields si and so always stays at 0
        free(arr);
    }
    // ex2: In my laptop nothing changed when I remove free() function and left.
    // Statistics also were the same even when I changed memory allocation from 10mb to 500 mb
    // ex3: The field 'VIRT' in a table showed the same amount of bytes as I allocated at each iteration
    // Moreover, I mentioned that while allocating 10 mb, programs uses barely 1% of CPU and 16-20%
    // while allocating 500 mb
}
