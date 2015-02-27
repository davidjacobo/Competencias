#include <stdio.h>
int main(){
    long long int N, i, sum, x, y;

    scanf("%lld",&N);
    sum = 0;

    for(i=1;i<=N;i++){
        scanf("%lld", &y);
        x = y*i-sum;
        sum+= x;
        if(i!=1) printf(" ");
        printf("%lld", x);
    }
    printf("\n");
    return 0;
}
