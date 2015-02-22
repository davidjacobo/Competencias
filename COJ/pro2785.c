#include <stdio.h>

int main(){
    int total = 0;
    int N,t,i=0;

    scanf("%d", &N);
    while(i++<N) {
        scanf("%d", &t);
        total+= t;
    }

    double out = (double)total/N;
    printf("%.2f\n",out);
    return 0;
}
