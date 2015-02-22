#include <stdio.h>
int main(){
    int N,a,b,t;
    scanf("%d",&N);

    a = 1;
    b = 0;
    while(N-->0){
        t = b;
        b = a+b;
        a = t;
    }
    printf("%d %d\n",a,b);
    return 0;
}
