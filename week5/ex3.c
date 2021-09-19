#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int bConsumerSleeping = 0, bProducerSleeping = 0;
int position = 0;

void consume(void* x){
    int tmp = 0;
    while(1){
        if(bConsumerSleeping == 1){
            continue;
        }

        if(tmp < 100){
            printf("I am consumer - %d\n", position);
        }

        if(position > 0){
            bProducerSleeping = 0;
            --position;
            ++tmp;
        }else{
           bConsumerSleeping = 1;
        }
    }
}

void produce(void* x){
    int tmp = 0;
    while(1){
        if(bProducerSleeping == 1){
            continue;
        }

        if(tmp < 100){
            printf("I am producer - %d\n", position);
        }

        if(position <= 100){
            bConsumerSleeping = 0;
            ++position;
            ++tmp;
        }else{
            bProducerSleeping = 1;
        }
    }
}

int main(){
	pthread_t tProduce, tConsume;
    pthread_create(&tProduce, NULL, &produce, NULL);
    pthread_create(&tConsume, NULL, &consume, NULL);

    pthread_join(tProduce, NULL);
    pthread_join(tConsume, NULL);
}

