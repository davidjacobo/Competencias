#include <cstdio>
#include <vector>
#include <queue>
#define MAX_N 20001
#define MAX_M 50001
#define INF 2000000000
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vii graph[MAX_N];
int distances[MAX_N];

void dijkstra(int S,int T){
    priority_queue<ii> pq;
    int i,j;
    int x,y,w;
    for(i=0;i<MAX_N;i++)
        distances[i] = INF;

    distances[S] = 0;
    pq.push(ii(0,S));
    while(!pq.empty()){
        x = pq.top().second;
        if(x==T) return;
        w = -pq.top().first;
        pq.pop();
        if(w!=distances[x]) continue;

        for(j=0;j<graph[x].size();j++){
            y = graph[x][j].first;
            w = graph[x][j].second;
            if(distances[x]+w < distances[y]){
                distances[y] = distances[x]+w;
                pq.push(ii(-distances[y],y));
            }
        }
    }
}

void clean(int V){
    for(int i=0;i<V;i++){
        graph[i].clear();
    }
}

int main(){
    int S,T,Q,counter = 1;
    int V,E;
    int x,y,w;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d %d %d %d",&V,&E,&S,&T);
        while(E--){
            scanf("%d %d %d",&x,&y,&w);
            graph[x].push_back(ii(y,w));
            graph[y].push_back(ii(x,w));
        }

        dijkstra(S,T);
        printf("Case #%d: ",counter++);
        if(distances[T]!=INF){
            printf("%d\n",distances[T]);
        } else {
            printf("unreachable\n");
        }

        clean(V);
    }
    return 0;
}
