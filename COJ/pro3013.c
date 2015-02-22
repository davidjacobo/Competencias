#include <stdio.h>
#include <math.h>

int main(){
    int N, t;
    scanf("%d",&N);
    while(N-->0){
        scanf("%d",&t);
        printf("%d\n",(int)pow(2.0,t)-1);
    }
    return 0;
}
