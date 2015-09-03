#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX_V 100001
#define INF (1<<30)

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii graph[MAX_V],t_dist[2];
int V,E,D,distances[2][MAX_V], power_sum[MAX_V];

void dijkstra(int source){
    priority_queue<ii> pq;
    int dim = source, ind = 0;
    for(int i=0;i<V;++i)    distances[dim][i] = INF;

    distances[dim][source] = 0;
    pq.push(ii(0, source));
    power_sum[ind++] = 0;

    while(!pq.empty()){
        int y = pq.top().second;
        int dis = -pq.top().first;
        pq.pop();

        if(distances[dim][y] < dis) continue;
        t_dist[dim].push_back(ii(dis, y));
        power_sum[ind++] = dis + power_sum[ind-2];

        for(int i=0;i<graph[y].size();++i){
            int v = graph[y][i].first;
            int w = graph[y][i].second;

            if(distances[dim][y] + w < distances[dim][v]){
                distances[dim][v] = distances[dim][y] + w;
                pq.push(ii(-distances[dim][v], v));
            }
        }
    }

    t_dist[dim].push_back(ii(INF,INF));
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

    for(int i=0;i<V;++i){
        vector<ii>::iterator it = upper_bound(t_dist[1].begin(), t_dist[1].end(), ii(D-t_dist[0][i].first-2,INF));
        int j = it-t_dist[1].begin();
        ans+= (D*j-j-power_sum[j]-t_dist[0][i].first*j);

        /*if(distances[0][i]+distances[1][i] < D){
            ans+= (D-distances[0][i]-distances[1][i]-1);
            printf("reducing to: %lld\n",ans);
        }*/

    }
    printf("%lld\n",ans);
    return 0;
}
