#include <stdio.h>
#include <stdbool.h>

typedef struct num{
    int at, bt, id;
}num;

void equals(num* a, num* b){
    a->at = b->at;
    a->bt = b->bt;
    a->id = b->id;
}

int max(int a, int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a < b ? a : b;
}

void bubbleSort(num arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j].at > arr[j+1].at || arr[j].at == arr[j+1].at && arr[j].id > arr[j+1].id){
                num tmp;
                equals(&tmp, &arr[j]);
                equals(&arr[j], &arr[j+1]);
                equals(&arr[j+1], &tmp);
            }
        }
    }
}

int main(){
    int n;
    printf("Number of processes: ");
    scanf("%d", &n);
    printf("===============================================\n");


    int i;
    num arr[n];
    bool done[n];
    int waves[n];
    for(i = 0; i < n; ++i){
        printf("Process #%d\nArrival Time: ", i+1);
        scanf("%d", &arr[i].at);
        printf("Burst Time: ");
        scanf("%d", &arr[i].bt);
        arr[i].id = i+1;
        printf("===============================================\n");

        done[i] = false;
        waves[i] = 0;
    }

    int q;
    printf("Specify your quantum: ");
    scanf("%d", &q);

    bubbleSort(arr, n);

    int rem_bt[n];
    for(i = 0; i < n; ++i){
        rem_bt[i] = arr[i].bt;
    }

    int wt[n], btSum = 0, tat[n], ct[n];
    bool smthUndone = true;
    int timer = 0;
    while(smthUndone){
        smthUndone = false;
        for (i = 0; i < n; i++) {
            if (done[i]) {
                continue;
            }

            timer = max(timer, arr[i].at);
            ++waves[i];

            ct[i] = min(rem_bt[i], q) + timer;
            tat[i] = ct[i]-arr[i].at;
            wt[i] = tat[i] - min(rem_bt[i], q);
            if(waves[i] > 1){
                wt[i] -= q*(waves[i]-1);
            }

            rem_bt[i] -= min(rem_bt[i], q);
            if(rem_bt[i] == 0){
                done[i] = true;
            }
            timer = ct[i];
        }
        for(i = 0; i < n; ++i)
            if(!done[i]) smthUndone = true;
    }


    float avgTat = 0, avgWt = 0;
    for (i = 0; i < n; i++) {
        avgTat += tat[i];
        avgWt += wt[i];
    }
    avgTat /= n;
    avgWt /= n;

    printf("Statistics\n=================================================================================================\n");
    printf("\tProcess Id\tArrival time\tBurst Time\tCompletion Time\t\tWaiting Time\tTurnaround time\n");
    for(i = 0; i < n; ++i){
        printf("\t\t%d \t\t%d \t\t%d \t\t%d \t\t%d \t\t%d\n", arr[i].id, arr[i].at, arr[i].bt, ct[i], wt[i], tat[i]);
    }

    printf("\tAverage\t\t\t\t\t\t\t\t\t%f\t%f\n", avgWt, avgTat);
}
