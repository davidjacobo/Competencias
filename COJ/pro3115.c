#include <stdio.h>
int maximo(int a,int b){
    return (a>b)?a:b;
}

int main(){
    int T,N,x,y,total,max,i;

    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        total = i = max  = 0;
        while(i++<N){
            scanf("%d %d",&x,&y);
            max = maximo(max, x+y);
            total+= (x+y);
        }

        printf("%d\n",(max*N-total));
    }
}
