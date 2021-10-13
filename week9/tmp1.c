#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Number of pages:\n");
    int pn;     //number of pages
    scanf("%d", &pn);
    FILE *file = fopen("input.txt", "r");
    long long counter[pn];
    int PT[pn]; //page table
    for (int i = 0; i < pn; i++){
        PT[i] = -1;
        counter[i] = 0;
    }
    int miss = 0;
    int hit = 0;
    for (int j = 0; j < 1000; j++){
        int ref;
        fscanf(file, "%d", &ref);
        int flag = 0;
        int id = -1;
        for (int i = 0; i < pn; i++){
            if (PT[i] == ref){
                hit++;
                flag = 1;
                id = i;
                break;
            }
        }
        if (!flag){
            miss++;
            for (int i = 0; i < pn; i++){
                if (PT[i] == -1){
                    id = i;
                    break;
                }
            }
            if (id == -1){
                int min = counter[0];
                id = 0;
                for (int i = 1; i < pn; i++){
                    if (counter[i]<min){
                        min = counter[i];
                        id = i;
                    }
                }
            }
            PT[id] = ref;
        }
        for (int i = 0; i <pn; i++){
            counter[i] = counter[i] >> 1;
        }
        counter[id] = counter[id] | (1 << 32);
    }
    printf("Hits: %d\n", hit);
    printf("Miss: %d\n", miss);
    printf("Hits/Miss ratio: %f",(float)hit/(float)miss);
    fclose(file);
    return 0;
}
