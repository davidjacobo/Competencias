#include <stdio.h>

void makeOdd(int *p){
    int t = *p;
    while((t&1)==0){
        t>>=1;
    }
    *p = t;
}

void makeEven(int *p){
    //rekt some sheit
    *p<<=1;
}

int main(){
    int N, t;
    scanf("%d", &N);
    while(N-->0){
        scanf("%d", &t);
        if((t&1)==0) {
            makeOdd(&t);
        } else {
            makeEven(&t);
        }
        printf("%d\n", t);
    }
    return 0;
}
