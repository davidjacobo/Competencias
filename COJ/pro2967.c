#include <stdio.h>
#include <stdlib.h>

void calc_primes(int *p){
    int i,j;
    for(i=0;i<401;i++)
        p[i] = 1;

    p[0] = p[1] = 0;
    for(i=4;i<401;i+=2)
        p[i] = 0;
    for(i=3;i<401;i+=2){
        if(p[i]){
            for(j=i*i;j<401;j+=i)
                p[j] = 0;
        }
    }
}

int count_times(int *p,int n){
    int i, half = n>>1, counter = 0;
    for(i=2;i<=half;i++){
        if(!p[i]) continue;
        if(p[n-i]) counter++;
    }   
    return counter;
}

int main(){
    int *primes = (int *)malloc(401*sizeof(int));
    int N, t;
    calc_primes(primes);
    scanf("%d",&N);

    while(N-->0){
        scanf("%d",&t);
        printf("%d\n",count_times(primes, t));
    }

    return 0;
}
