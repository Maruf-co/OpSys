#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <pthread.h>

void* routine(void* args){
    pthread_t x = pthread_self();
    printf("Inside job %d\n", x);
    return NULL;
}

int main(){
	unsigned long x = pthread_self();
	pthread_t thread_id;
	int i;
	for(i = 0; i < 5; ++i){
        pthread_create(&thread_id, NULL, routine, NULL);
        x = pthread_self();
        printf("x = %d\n", x);

	}
	exit(EXIT_SUCCESS);

}

