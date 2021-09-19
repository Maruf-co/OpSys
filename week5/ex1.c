#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{
    pthread_t threadId;
    int threadNum;
    char* str;
} ThreadInfo;


void* job(void* args){
    ThreadInfo* t = (ThreadInfo*)args;
    printf("I am Thread %d\n", t->threadNum);

}

int main(){
	ThreadInfo* tInfo;

	int N;
	printf("N = ");
	scanf("%d", &N);

	tInfo = calloc(N, sizeof(ThreadInfo));
    int i;
	for(i = 0; i < N; ++i){
        printf("Creating thread number %d\n", i);

        tInfo[i].threadNum = i;
        pthread_create(&tInfo[i].threadId, NULL, job, (void*)&tInfo[i]);
        pthread_join(tInfo[i].threadId, NULL);

        printf("Terminating thread number %d\n", i);
	}
    pthread_exit(NULL);
}

