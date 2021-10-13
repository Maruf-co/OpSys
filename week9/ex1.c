#include <stdio.h>

struct frame{
    int val, fr, r_bit;

};

int search(struct frame frames[], int n, int a){
    int i;
    for(i = 0; i < n; ++i){
        if(frames[i].fr == a){
            return i;
        }
    }
    return -1;
}


int main(){
    int i, j; // Counters inside for loop

    int n, m;
    scanf("%d %d", &n, &m);
    int t[m], a[m], b[m];
    struct frame frames[n];
    for(i = 0; i < n; ++i){
        frames[i].fr = -1;
        frames[i].val = 0;
        frames[i].r_bit = 0;
    }

    for(i = 0; i < m; ++i){
        scanf("%d%d", &t[i], &a[i]);
        b[i] = 0;
    }


    int frSize = 0;
    for(i = 0; i < m; ++i){

        if(i != 0 && t[i] != t[i-1]){
            for(j = 0; j < frSize; ++j){
                frames[j].val = (frames[j].val >> 1) | (frames[j].r_bit << 7);
                frames[j].r_bit = 0;
            }
        }

        int pos = search(frames, frSize, a[i]);
        if(pos == -1){
            ++frSize;
            if(frSize > n){
                frSize = n;
                int minVal = frames[0].val, minId = 0, minPage = frames[0].fr;
                for(j = 1; j < frSize; ++j){
                    if(minVal > frames[j].val || minVal == frames[j].val && minPage > frames[j].fr){
                        minVal = frames[j].val;
                        minId = j;
                        minPage = frames[j].fr;
                    }
                }
                frames[minId].val = 0;
                frames[minId].fr = a[i];
                frames[minId].r_bit = 1;
            }else{
                frames[frSize-1].val = 0;
                frames[frSize-1].fr = a[i];
                frames[frSize-1].r_bit = 1;
            }
        }else{
            frames[pos].r_bit = 1;
            b[i] = 1;
        }
    }
    float hit = 0, miss;
    for(i = 0; i < m; ++i){
        hit += b[i];
        printf("%d\n", b[i]);
    }
    miss = m - hit;
    printf("%f", (float)hit/(float)miss);
}
