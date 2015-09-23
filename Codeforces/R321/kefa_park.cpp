#include <iostream>
#include <cstring>
#include <vector>
#define MAX_N 100001

using namespace std;
typedef vector<int> vi;
int parent[MAX_N], degree[MAX_N];
bool is_cat[MAX_N], seen[MAX_N];
int v,m, ans;
vi graph[MAX_N];

void dfs(int u,int consec, bool fucked){
    if(is_cat[u]) ++consec;
    else consec = 0;
    seen[u] = true;

    if(consec > m) fucked = true;

    int outs = 0;
    for(int i=0;i<graph[u].size();++i){
        int v = graph[u][i];

        if(!seen[v]){
            ++outs;
            parent[v] = u;
            dfs(v,consec,fucked);
        }
    }

    if(outs==0){
        if(!fucked) ++ans;
    }
}

int main(){
    int x,y;
    cin>>v>>m;
    memset(degree, 0, sizeof degree);
    memset(is_cat, false, sizeof is_cat);
    memset(seen, false, sizeof seen);

    for(int i=0;i<v;++i){
        cin>>x;
        is_cat[i] = (x==1)?true:false;
    }

    for(int i=0;i<v-1;++i){
        cin>>x>>y;
        --x; --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    ans = 0;
    dfs(0, 0, false);
    cout<<ans<<endl;
    return 0;
}
