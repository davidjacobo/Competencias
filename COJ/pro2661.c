#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *p = (char *)malloc(1000001);
    int i,len, sum;
    while(scanf("%s", p)!=EOF){
        len = strlen(p);
        sum = 0;
        for(i=0;i<len;i++)
            sum = (sum + p[i]-'0')%3;
    
        switch(sum){
            case 0:
                printf("1\n");
                break;
            case 1:
                printf("7\n");
                break;
            case 2:
                printf("4\n");
        }
    }
    return 0;
}
