#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX_N 1001
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> ii_i;

int cost[MAX_N], dist[MAX_N][MAX_N];

void clear(){
    for(int i=0;i<MAX_N;i++)
        for(int j=0;j<MAX_N;j++)
            dist[i][j] = INF;
}

int dp(int N){
    priority_queue<ii_i> pq;
    int step, index;
    int x, d;
    dist[1][2] = cost[2];
    if(N==2) return cost[2];
    pq.push(ii_i(ii(-cost[2],2),1));
    
    while(!pq.empty()){
        d = pq.top().first.first;
        index = pq.top().first.second;
        step = pq.top().second;
        if(index==N) return dist[step][N];
        pq.pop();
        //printf("step: %d  index: %d   dist: %d\n",step,index,-d);

        if(-d != dist[step][index]) continue;

        //try backwards
        x = index-step;
        if(x > 0){
            d = dist[step][index] + cost[x];
            if(dist[step][x] > d){
                dist[step][x] = d;
                pq.push(ii_i(ii(-d,x),step));
            }
        }
        //try forward
        x = index+step+1;
        if(x <= N && step+1<=N){
            d = dist[step][index] + cost[x];
            if(dist[step+1][x] > d){
                dist[step+1][x] = d;
                pq.push(ii_i(ii(-d,x),step+1));
            }
        }
    }
    return -1;
}

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&cost[i+1]);
    clear();

    printf("%d\n", dp(N));
    return 0;
}
