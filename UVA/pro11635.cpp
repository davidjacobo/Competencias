#include <cstdio>
#include <queue>
#include <vector>
#define MAX_N 10002
#define MAX_H 103
#define INF 2000000000
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int hotel[MAX_H], distances[MAX_N];
bool reachable[MAX_H][MAX_H];
vii graph[MAX_N];

void clear(int V,int H){
    for(int i=0;i<V;i++)
        graph[i].clear();
    
    for(int i=0;i<H;i++)
        for(int j=0;j<H;j++)
            reachable[i][j] = false;
}

int bfs(int V){
    queue<int> q;
    q.push(V-1);

    for(int i=0;i<V;i++)
        distances[i] = INF;
    distances[V-1] = 0;

    int x;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i=0;i<V;i++){
            if(reachable[x][i] && distances[i] == INF){
                distances[i] = distances[x]+1;
                q.push(i);
            }
        }        
    }
    return distances[V-1];
}

void dijkstra(int S,int V,int H){
    priority_queue<ii> pq;
    int y,w,start = S;
    S = hotel[S];

    for(int i=0;i<V;i++)
        distances[i] = INF;
    distances[S] = 0;
    pq.push(ii(0,S));

    while(!pq.empty()){
        w = -pq.top().first;
        S = pq.top().second;
        pq.pop();
        if(w!=distances[S]) continue;

        for(int i=0;i<graph[S].size();i++){
            y = graph[S][i].first;
            w = graph[S][i].second;

            if(distances[y] > distances[S]+w){
                distances[y] = distances[S]+w;
                pq.push(ii(-distances[y],y));
            }
        }
    }

    S = start;
    int D;
    for(int i=0;i<H;i++){
        D = hotel[i];
        if(distances[D]<=600)
            reachable[S][i] = reachable[i][S] = true;
    }

}

int main(){
    int V,E,H;
    int x,y,w;

    while(1){
        scanf("%d",&V);
        if(V==0) break;
        scanf("%d",&H);
        for(int i=0;i<H;i++){
            scanf("%d",&w);
            hotel[i] = w-1;
        }
        hotel[H] = 0;
        hotel[H+1] = V-1;
        H+= 2;
        clear(V,H);

        scanf("%d",&E);
        while(E--){
            scanf("%d %d %d",&x,&y,&w);
            x--; y--;
            graph[x].push_back(ii(y,w));
            graph[y].push_back(ii(x,w));
        }

        for(int i=0;i<H;i++){
            dijkstra(i,V,H);
        }

        bfs(H);
        printf("%d\n",(distances[H-2]==INF)?-1:distances[H-2]-1);
    }
    return 0;
}
