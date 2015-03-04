#include <stdio.h>

int main(){
    int x0, y0, x1, y1;
    int x2, y2, x3, y3;
    scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
    scanf("%d %d %d %d",&x2,&y2,&x3,&y3);

    int i,j,p,q;
    int sumA =0, sumB=0;
    for(i=x0;i<=y0;i++){
        for(j=x1;j<=y1;j++){
            for(p=x2;p<=y2;p++){
                for(q=x3;q<=y3;q++){
                    if(i+j > p+q) sumA++;
                    else if(i+j < p+q) sumB++;
                }
            }
        }
    }

    if(sumA > sumB) printf("Gunnar\n");
    else if(sumA < sumB) printf("Emma\n");
    else printf("Tie\n");
    return 0;
}
