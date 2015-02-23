#include <stdio.h>
#include <stdlib.h>

int main(){
    char *p = (char *)malloc(100);
    long long int total = 0;
    int t;

    while(scanf("%s", p) != EOF){
        scanf("%d", &t);
        if(*p=='s'){
            total+= t;
        } else {
            total-= t;
        }
    }
    printf("resultado: %lld\n", total);
    return 0;
}
