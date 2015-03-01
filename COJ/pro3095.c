#include <stdio.h>
#define EMPTY 1000000
int pairs[10][10];

void clean(){
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            pairs[i][j] = EMPTY;
}

int calc_fib(long long int n){
    if(n>=60) n = (n%60);

    //pairs[0][1] = pairs[1][0] = 1;
    if(n==0) return 0;
    if(n==1 || n==2) return 1;
    int a = 1, b = 1, t;
    int counter = 2;
    while(counter++ < n){
        /*if(pairs[a][b] != EMPTY){
            printf("done %d-%d %d %d\n",a,b, counter, pairs[a][b]);
            break;
        }*/
        t = (a+b)%10;
        //pairs[a][b]  = t;
        a = b;
        b = t;
    }
    return t;
}

int main(){
    long long int n;
    clean();

    while(scanf("%lld", &n)!= EOF){
        printf("%d\n", calc_fib(n));
    }
    return 0;
}
