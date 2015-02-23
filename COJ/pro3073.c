#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *p = (char *)malloc(101);
    int i, len, N;
    scanf("%d",&N);

    while(N-->0){
        scanf("%s", p);
        len = strlen(p);
        if(len > 10) {
            printf("%c%d%c\n",p[0],len-2,p[len-1]);
        } else {
            printf("%s\n",p);
        }
    }
    return 0;
}
