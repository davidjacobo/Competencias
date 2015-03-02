#include <stdio.h>
int cows[100001][2];

int solve(int N){
    int lastP, lastV;
    int i, groups = 1;
    lastP = cows[--N][0];
    lastV = cows[N--][1];
    while(N>-1){
        if(cows[N][1] > lastV /*|| (cows[N][1]==lastV && cows[N][0]+1==lastP)*/){
            lastP--;
            //lets keep the min speed
        } else {
            lastV = cows[N][1];
            lastP = cows[N][0];
            groups++;
        }
        N--;
    }
    return groups;
}

int main(){
    int N, i;
    scanf("%d",&N);
    i=0;
    while(i<N){
        scanf("%d %d",&cows[i][0],&cows[i][1]);
        i++;
    }

    printf("%d\n", solve(N));
    
    return 0;
}
