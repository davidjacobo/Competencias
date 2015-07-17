#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int T, N, K;
    int odd,even,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&K);
        odd = even = 0;
        for(int i=0;i<N;++i){
            scanf("%d",&t);
            if((t&1)==0){
                ++even;
            } else {
                ++odd;
            }
        }

        if(K==1) {
            if((odd&1)==0) {
                printf("odd\n");
            } else {
                printf("even\n");
            }
        } else {
            printf("even\n");
        }
    }
    return 0;
}
