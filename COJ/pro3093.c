#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i,len,total;
    char *p = (char *)malloc(100001);
    scanf("%s", p);
    len = strlen(p);

    total = (p[0]-'A'+1)%26;
    for(i=1;i<len;i++)
        total = (total*(p[i]-'A'+1))%26;
    if(total<10)
        printf("0%d\n", total);
    else
        printf("%d\n", total);
    return 0;
}
