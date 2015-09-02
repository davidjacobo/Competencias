#include <cstdio>
#include <queue>
#include <vector>
#define MAX_V 100001
#define INF (1<<30)

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii graph[MAX_V];
int V,E,D,distances[2][MAX_V];

void dijkstra(int source){
    priority_queue<ii> pq;
    int dim = source;
    for(int i=0;i<V;++i)    distances[dim][i] = INF;

    distances[dim][source] = 0;
    pq.push(ii(0, source));

    while(!pq.empty()){
        int y = pq.top().second;
        int dis = -pq.top().first;
        pq.pop();

        if(distances[dim][y] < dis) continue;

        for(int i=0;i<graph[y].size();++i){
            int v = graph[y][i].first;
            int w = graph[y][i].second;

            if(distances[dim][y] + w < distances[dim][v]){
                distances[dim][v] = distances[dim][y] + w;
                pq.push(ii(-distances[dim][v], v));
            }
        }
    }
}

int main(){
    int x,y,w;
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;++i){
        scanf("%d %d %d",&x,&y,&w);
        --x; --y;
        //Re-label so S=0, T=1
        if(x==V-1) x = 1;
        else if(x==1) x = V-1;
        if(y==V-1) y = 1;
        else if(1==y) y = V-1;

        graph[x].push_back(ii(y,w));
        graph[y].push_back(ii(x,w));
    }

    dijkstra(0);
    dijkstra(1);

    //This is the original minimum distance between the capitals
    D = distances[1][0];

    ll ans = 0;
    for(int i=0;i<V-1;++i){
        //Could need to improve here, maybe prunning starting points
        if(distances[0][i] >= D && distances[1][i] >= D) continue;
        for(int j=i+1;j<V;++j){
            w = distances[0][i] + distances[1][j];
            if(w < D){
                ans+= (D-w-1);
            }
            w = distances[0][j] + distances[1][i];
            if(w < D){
                ans+= (D-w-1);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
