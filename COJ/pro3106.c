#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindrome(char *cad,int len){
    int i,j,m=(len-1)>>1;
    for(i=0,j=len-1;i<=m;i++,j--)
        if(cad[i]!=cad[j]) return 0;
    return 1;
}

int main(){
    char *a,*b;
    a = (char *)malloc(11);
    b = (char *)malloc(22);
    scanf("%s %s",a,b);
    strcat(a, b);
    int len = strlen(a);
    
    if(palindrome(a,len)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
