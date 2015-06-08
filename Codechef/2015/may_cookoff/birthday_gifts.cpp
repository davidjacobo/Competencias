#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_V 100001
#define INV -1
#define UNK 0
#define SEEN 1
#define PROC 2
#define CYCL 3
using namespace std;

typedef long long ll;
typedef pair<ll,int> ll_i;
vector<int> back_graph[MAX_V];

int cost[MAX_V], V, color[MAX_V], graph[MAX_V], parent[MAX_V];
ll distances[MAX_V], total, branch, max_branch;

void clear(){
    for(int i=1;i<=V;++i){
        back_graph[i].clear();
    }
}

void climb_branch(int v,ll branch){
    color[v] = CYCL;
    branch+= cost[v];
    max_branch = max(max_branch, branch);
    if(back_graph[v].size() == 1)
        climb_branch(back_graph[v][0], branch);
}

void cycle_uppercut(int x,int y){
    ll ans = 0, cycle = cost[y], sum = 0;

    int v = x;
    while(v!=y){
        cycle+= cost[v];
        color[v] = CYCL;
        v = parent[v];
    }
    color[v] = CYCL;
    sum = cycle;

    v = x;
    while(v!=y){
        for(int k=0;k<back_graph[v].size();++k){
            int w = back_graph[v][k];
            if(color[w]==CYCL) continue;
            max_branch = 0;
            climb_branch(w, 0);
            if(max_branch > 0)
                sum+= max_branch;
        }

        distances[v] = ans;
        v = parent[v];
    }

    distances[v] = ans;   
    if(sum > 0) total+= sum;
}

void dfs(int v){
    if(color[v]==CYCL) return;
    color[v] = SEEN;
    int y = graph[v];

    if(color[y]==UNK){
        parent[y] = v;
        dfs(y);
    } else if(color[y]==SEEN){
        //set distances to all the vertices within the cycle
        cycle_uppercut(v,y);
    }
}

int main(){
    int T,x,y;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&V);
        clear();

        for(int i=1;i<=V;++i){       
            scanf("%d",&x);
            graph[i] = x;
            back_graph[x].push_back(i);
        }
        for(int i=1;i<=V;++i){
            scanf("%d",&cost[i]);
        }

        memset(color, UNK, sizeof(color));
        memset(parent, INV, sizeof(parent));

        total = 0;
        for(int i=1;i<=V;++i)
            if(CYCL!=color[i])
                dfs(i);

        printf("%lld\n",total);
    }
    return 0;
}
