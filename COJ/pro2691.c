#include <stdio.h>

int main(){
    int N,M;
    int totalN,totalM,t;

    totalN = totalM = 0;
    scanf("%d %d",&N,&M);
    while(N-->0){
        scanf("%d",&t);
        totalN+= t;
    }
    while(M-->0){
        scanf("%d",&t);
        totalM+= t;
    }

    if(totalM==totalN) {
        printf("tie\n");
    } else if(totalN > totalM) {
        printf("first win\n");
    } else {
        printf("second win\n");
    }
    return 0;
}
