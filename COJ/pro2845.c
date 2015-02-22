#include <stdio.h>

int main(){
    double x,y;
    while(1){
        scanf("%lf %lf",&x,&y);
        if(x==0 && y==0) break;
        else if(x==0 || y==0) printf("AXIS\n");
        else if(x>0 && y>0) printf("Q1\n");
        else if(x<0 && y>0) printf("Q2\n");
        else if(x<0 && y<0) printf("Q3\n");
        else printf("Q4\n");
    }
    printf("AXIS\n");
}
