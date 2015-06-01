#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define MAX_V 203
#define INF 20000000

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> ii_i;
typedef vector<ii_i> vii_i;
int V,E,S,T, parent[MAX_V];
vii_i graph[MAX_V];

void insert(int x,int y,int t){
    graph[x].push_back(ii_i(ii(y,t),t));
    graph[y].push_back(ii_i(ii(x,t),0));
}

void bfs(int u){
    memset(parent, -1, sizeof parent);
    queue<int> q;
    parent[u] = u;
    q.push(u);

    while(!q.empty()){
        u = q.front();  q.pop();

        for(int i=0;i<graph[u].size();++i){
            int v = graph[u][i].first.first;

            if(parent[v]==-1 && graph[u][i].second > 0){
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int find_min(int v,int min_edge){
    if(v==parent[v]) {
        return min_edge;
    } else {
        int u = parent[v];
        for(int i=0;i<graph[u].size();++i){
            int y = graph[u][i].first.first;
            if(y==v){
                min_edge = min(graph[u][i].second, min_edge);
                min_edge = find_min(u, min_edge);
                graph[u][i].second-= min_edge;
                for(int j=0;j<graph[v].size();++j){
                    int a = graph[v][j].first.first;
                    if(a==u){
                        graph[v][j].second+= min_edge;
                        return min_edge;
                    }
                }
            }
        }
        return 0;
    }
}

int edmonds_karp(){
    int flow = 0, augment;
    do{
        bfs(0);
        if(parent[T]==-1) break; //if T has no parent there is no way to reach it
        augment = find_min(T, INF);
        flow+= augment;
    }while(augment > 0);
    return flow;
}

int print_used(int u,int v){
    for(int i=0;i<graph[u].size();++i){
        int y = graph[u][i].first.first;
        if(v==y){
            return graph[u][i].first.second - graph[u][i].second;
        }
    }
    return 0;
}

int main(){
    int sum = 0,sum2 = 0,x,y,t;
    cin>>V>>E;
    S = 0;
    T = (V<<1)+1;
    for(int i=0;i<V;++i){
        cin>>t;
        insert(S, i+1, t);
        insert(i+1, i+1+V, t);
        sum+= t;
    }

    for(int i=0;i<V;++i){
        cin>>t;
        insert(i+1+V, T, t);
        sum2+= t;
    }

    for(int i=0;i<E;++i){
        cin>>x>>y;
        insert(x, y+V, INF);
        insert(y, x+V, INF);
    }

    int ans = edmonds_karp();
    if(ans==sum && sum2==sum) {
        cout<<"YES"<<endl;
        for(int i=1;i<=V;++i){
            for(int j=1;j<=V;++j){
                cout<<print_used(i,j+V)<<" ";
            }
            cout<<endl;
        }
    } else {
        cout<<"NO"<<endl;
    }
    

    return 0;
}
