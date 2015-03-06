#include <stdio.h>
#define INF 2000000000
int sums[100002];

int binary(int key, int q){
    int p = 0, m;

    while(p<=q){
        m = (p+q)/2;
        if(sums[m]>key && sums[m-1]<=key){
            return m-1;
        } else if(sums[m]>key) {
            q = m-1;
        } else {
            p = m+1;
        }
    }
    return -1;
}

int main(){
    int N,Q,i,t,first;
    while(scanf("%d %d",&N,&Q)!=EOF){
        i=1;
        sums[0] = 0;
        sums[1] = 1;
        scanf("%d", &t);

        while(i++<N){
            scanf("%d", &t);
            sums[i] = t + sums[i-1];
        }
        sums[N+1] = INF;

        first = 1;
        while(Q--){
            if(!first) printf(" ");
            first = 0;
            scanf("%d",&t);
            t = binary(t, N+1);
            printf("%d",(t<=N)?t:N);
        }
        printf("\n");
    }
    return 0;
}
