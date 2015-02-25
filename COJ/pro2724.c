#include <stdio.h>

char mat[100][100];
void dfs(int x,int y,int M,int N,int *area){
    if(x<0 || x>=M || y<0 || y>=N) return;  //out of range
    if(!mat[x][y]) return;                  //already checked or invalid

    (*area)++;
    mat[x][y] = 0;

    dfs(x-1,y  ,M,N,area);
    dfs(x  ,y-1,M,N,area);
    dfs(x+1,y  ,M,N,area);
    dfs(x  ,y+1,M,N,area);
}

void clean(int M,int N){
    int i,j;
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            mat[i][j] = 0;
}

int main(){
    int N,M,K;

    scanf("%d %d %d",&M,&N,&K);
    clean(M,N);
    int i=0,j,x,y;
    while(i++<K){
        scanf("%d %d",&x,&y);
        x--; y--;
        mat[x][y] = 1;
    }

    int max_area = 0, area = 0;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(mat[i][j])
                area = 0;
                dfs(i,j,M,N,&area);
                if(area > max_area) 
                    max_area = area;
        }
    }
    printf("%d\n", max_area);
    return 0;
}
