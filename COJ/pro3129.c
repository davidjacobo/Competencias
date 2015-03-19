#include <stdio.h>

int main(){
    int t,n,p;
    char cad[5];
    scanf("%d",&t);
    while(t--){
        scanf("%d %s %d",&n,cad,&p);            
        printf("%d\n",(cad[0]=='o')?p<<1:(p<<1)-1);
    }
    return 0;
}
