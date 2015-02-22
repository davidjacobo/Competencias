#include <stdio.h>
#include <stdlib.h>

int main(){
    char *p;
    int counter[] = {0,0,0,0};
    p = (char *)malloc(1001*sizeof(char));
    scanf("%s",p);

    char car;
    for(;*p!='\0';p++) {
        car = *p;
        if(car=='+') continue;
        else counter[car-'0']++;
    }

    char out[1001];
    int i = 0;
    while(counter[1]-->0){
        out[i++] = '1';
        out[i++] = '+';
    }
    while(counter[2]-->0){
        out[i++] = '2';
        out[i++] = '+';
    }
    while(counter[3]-->0){
        out[i++] = '3';
        out[i++] = '+';
    }
    out[--i] = '\0';
    printf("%s\n", out);
    return 0;
}
