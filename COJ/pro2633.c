#include <stdio.h>
#define PI 3.14159

double max(double a,double b){
    return (a>b)?a:b;
}

int main(){
    char type;
    double a,b,maximo;
    int N;

    scanf("%d", &N);
    maximo = -1.0;
    while(N){
        scanf("%c", &type);
        if(type=='S') {
            scanf("%lf", &a);
            maximo = max(maximo, (4.0 * PI * a * a * a)/3.0);
            N--;
        } else if(type=='C') {
            scanf("%lf %lf",&a,&b);
            maximo = max(maximo, (PI * a * a * b)/3.0);
            N--;
        } else if(type=='L'){
            scanf("%lf %lf",&a,&b);
            maximo = max(maximo, PI * a * a * b);
            N--;
        }
    }
    printf("%.3f\n", maximo);
    return 0;
}
