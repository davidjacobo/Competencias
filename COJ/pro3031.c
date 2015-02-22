#include <stdio.h>

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        if(a==0 && b==0) break;
        printf("%d %d / %d\n", (a/b), (a%b), b);
    }
    return 0;
}
