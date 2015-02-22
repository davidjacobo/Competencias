#include <stdio.h>
#include <stdlib.h>

void swap(long long int *a,long long int *b){
    *a^=*b;
    *b^=*a;
    *a^=*b;
}

int main(){
    char *p = (char *)malloc(21);
    long long int a,b;
    scanf("%s %lld %lld",p,&a,&b);
    if(b>a) swap(&a, &b);
    printf("%s %lld\n",p,(a-b));
    
    return 0;
}
