#include <stdio.h>
#include <stdlib.h>

int main(){
    char *p = (char *)malloc(1000001), car;
    int N,i;

    scanf("%d", &N);
    while(N-->0) {
        scanf("%s", p);
        for(;*p!='\0';p++) {
            car = *p;
            if(car>='a' && car<='z')
                putchar((char)(car + 'A' - 'a'));
            else
                putchar((char)(car + 'a' - 'A'));
        }
        putchar('\n');
    }
    return 0;
}
