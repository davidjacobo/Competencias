#include <stdio.h>
#define MAX_N 51
#define INF 1000000000
int graph[51][51];

void clean(int N){
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            graph[i][j] = INF;
}

void floyd(int N){
    int i,j,k,d;
    graph[0][0] = 0;
    graph[0][1] = 1;

    for(k=0;k<N;k++)
        for(i=0;i<N;i++)
            for(j=0;j<N;j++){
                d = graph[i][k] + graph[k][j];
                if(graph[i][j] > d)
                    graph[i][j] = d;
            }
}

int main(){
    int T,N,L,Q;
    int x,y;
    scanf("%d",&T);
    while(T-->0){   
        scanf("%d %d %d",&N,&L,&Q);
        clean(N+1);
        while(L--){
            scanf("%d %d",&x,&y);
            graph[x][y] = 1;
        }

        floyd(N+1);
        while(Q--){
            scanf("%d",&x);
            printf("%d\n",(graph[0][x]==INF)?-1:graph[0][x]);
        }
    }
    return 0;
}
