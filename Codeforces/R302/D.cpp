#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX_V 3001
#define INV -1

using namespace std;
typedef vector<int> vi;

vi graph[MAX_V];
int V,E, dist[MAX_V][MAX_V], parent[MAX_V][MAX_V];

void bfs(int u){
    int x = u;
    queue<int> q;
    dist[u][u] = 0;
    q.push(u);
    
    while(!q.empty()){
        u = q.front(); q.pop();

        for(int i=0;i<graph[u].size();++i){
            int v = graph[u][i];

            if(dist[x][v]==INV){
                q.push(v);
                dist[x][v] = dist[x][u]+1;
                parent[x][v] = u;
            }
        }
    }
}

bool intersects(int s0,int t0,int s1,int t1){
    bool seen[MAX_V];
    memset(seen, false, sizeof(seen));
    
    int v = t0;
    do{
        seen[v] = true;
        v = parent[s0][v]; 
    }while(v!=INV);

    v = t1;
    do{
        if(seen[v]) return true;
        v = parent[s1][v];
    }while(v!=INV);
    return false;
}

int calculate_min(int s0,int t0,int d0,int s1,int t1,int d1){
    int ans = -1,t;
    if(dist[s0][t0] >d0 || dist[s1][t1]>d1) return ans;

    for(int i=1;i<=V;++i){
        for(int j=1;j<=V;++j){
            t = E-dist[s0][i]-dist[i][j]-dist[j][t0]-dist[s1][i]-dist[j][t1];
            if(dist[s0][i] + dist[i][j] + dist[j][t0] > d0) t = -1;
            if(dist[s1][i] + dist[i][j] + dist[j][t1] > d1) t = -1;
            ans = max(t, ans);
        }
    }
    return ans;
}

int main(){
    cin>>V>>E;
    int x,y,s0,t0,s1,t1,d0,d1;
    for(int i=0;i<E;++i){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cin>>s0>>t0>>d0>>s1>>t1>>d1;

    memset(dist, INV, sizeof(dist));
    memset(parent, INV, sizeof(parent));
    for(int i=1;i<=V;++i){
        bfs(i);
    }

    int ans;
    ans = max(calculate_min(s0,t0,d0,s1,t1,d1) , calculate_min(s0,t0,d0,t1,s1,d1));

    if(!intersects(s0,t0,s1,t1)) {
        if(dist[s0][t0] > d0 || dist[s1][t1] > d1) {
            ans = -1;
        } else {
            ans = max(ans , E - dist[s0][t0] - dist[s1][t1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
