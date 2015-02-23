#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *format(char *p){
    int len = strlen(p);
    if(*p=='a' || *p=='e' || *p=='i' || *p=='o' || *p=='u') {
        p[len] = 'c';
        p[len+1] = 'o';
        p[len+2] = 'w';
        p[len+3] = '\0';
    } else {
        p[len] = p[0];
        p[len+1] = 'o';
        p[len+2] = 'w';
        p[len+3] = '\0';
        p++;
    }
    return p;
}

int main(){
    char *p = (char *)malloc(1000000);
    int N;

    scanf("%d", &N);
    while(N-->0) {
        scanf("%s", p);
        p = format(p);
        printf("%s\n", p);
    }
    return 0;
}
