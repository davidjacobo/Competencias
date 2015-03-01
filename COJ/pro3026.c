#include <stdio.h>

int maximo(int a,int b){
    return (a>b)?a:b;
}

int minimo(int a,int b){
    return (a<b)?a:b;
}

int main(){
    int N;
    int minX, minY, maxX, maxY;
    int x,y;

    minX = minY = 101;
    maxX = maxY = 0;

    scanf("%d", &N);
    while(N--){
        scanf("%d %d",&x,&y);
        minX = minimo(minX, x);
        minY = minimo(minY, y);
        maxX = maximo(maxX, x);
        maxY = maximo(maxY, y);
    }
    
    x = maxX - minX;
    y = maxY - minY;
    x = maximo(x, y);
    x*= x;
    printf("%d\n",x);
    return 0;
}
