#include <stdio.h>
#include <string.h>

int main(){
    int mat[1001][3];
    int i,j,x,y;
    mat[0][0] = mat[1][1] = mat[2][2] = 1;
    mat[0][1] = mat[0][2] = mat[1][2] = 0;
    for(i=1;i<1001;i++) mat[i][0] = 1;

    for(i=2;i<1001;i++) 
        for(j=1;j<3;j++){
            mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
            //printf("%lld\n",mat[i][j]);
        }      

    while(scanf("%d %d",&x,&y)!=EOF) {
        printf("Triangles: %lld\n", ((long long int)mat[x][2]*y + (long long int)mat[y][2]*x));
        printf("Quadrilaterals: %lld\n", ((long long int)mat[x][2]*mat[y][2]));
        printf("\n");
    }
    return 0;
}
