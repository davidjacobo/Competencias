#include <cstdio>
#include <queue>
#define INF 2000000000
#define MAX_M 1000
#define MAX_N 1000
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> i_ii;
int addX[] = {1,-1,0,0};
int addY[] = {0,0,1,-1};
int distances[MAX_M][MAX_N], pesos[MAX_M][MAX_N];


void dijkstra(int M,int N){
    priority_queue<i_ii> pq;
    int i,j,k,x,y,w;

    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            distances[i][j] = INF;
    distances[0][0] = pesos[0][0];
    pq.push(i_ii(-distances[0][0],ii(0,0)));
    
    while(!pq.empty()){
        w = -pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();
        if(distances[x][y]!=w) continue;

        for(k=0;k<4;k++){
            i = x+addX[k];
            j = y+addY[k];
            if(i<0 || j<0 || i>=M || j>=N) continue;

            if(distances[x][y]+pesos[i][j] < distances[i][j]){
                distances[i][j] = distances[x][y]+pesos[i][j];
                pq.push(i_ii(-distances[i][j],ii(i,j)));
            }
        }
    }
}

int main(){
    int Q,M,N;
    int t;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d",&M,&N);
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++){
                scanf("%d", &pesos[i][j]);
            }

        dijkstra(M,N);
        printf("%d\n",distances[M-1][N-1]);
    }
    return 0;
}
