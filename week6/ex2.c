#include <stdio.h>


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

void bubbleSort(num arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            // Firstly sort by arrival time, then by burst time
            if (arr[j].at > arr[j+1].at || arr[j].at == arr[j+1].at && arr[j].bt > arr[j+1].bt){
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
    for(i = 0; i < n; ++i){
        printf("Process #%d\nArrival Time: ", i+1);
        scanf("%d", &arr[i].at);
        printf("Burst Time: ");
        scanf("%d", &arr[i].bt);
        arr[i].id = i+1;
        printf("===============================================\n");
    }
    bubbleSort(arr, n);

    int wt[n], btSum = 0, tat[n], ct[n];
    float avgTat = 0, avgWt = 0;
    for(i = 0; i < n; ++i){
        if(i == 0){
            wt[i] = arr[0].at;
        }else{
            wt[i] = max(arr[0].at + btSum - arr[i].at, 0);
        }
        btSum += arr[i].bt;

        tat[i] = wt[i] + arr[i].bt;
        ct[i] = tat[i] + arr[i].at;

        avgTat += tat[i];
        avgWt += wt[i];

    }

    printf("Statistics\n=================================================================================================\n");
    printf("\tProcess Id\tArrival time\tBurst Time\tCompletion Time\t\tWaiting Time\tTurnaround time\n");
    for(i = 0; i < n; ++i){
        printf("\t\t%d \t\t%d \t\t%d \t\t%d \t\t%d \t\t%d\n", arr[i].id, arr[i].at, arr[i].bt, ct[i], wt[i], tat[i]);
    }
    printf("\tAverage\t\t\t\t\t\t\t\t\t%f\t%f\n", avgWt/n, avgTat/n);






}
