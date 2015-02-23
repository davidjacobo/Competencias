#include <stdio.h>

int is_even(int n){
    return ((n&1)==0)?1:0;
}

void solve(int N,int n){
    int half = N>>1;
    if(n > half){
        if(is_even(n)){
            printf("%d %d %d\n",N-n+1,N-n+2,n-1);
        } else {
            printf("%d %d %d\n",N-n,N-n+1,n+1);            
        }
    } else {
        if(is_even(n)){
            printf("%d %d %d\n",n-1,N-n+1,N-n+2);
        } else {
            printf("%d %d %d\n",n+1,N-n,N-n+1);
        }
    }
}

int main(){
    int N, p;
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        scanf("%d",&p);
        solve(N,p);
    }
    return 0;
}
