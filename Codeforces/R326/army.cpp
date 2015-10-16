#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define MAX_N 1000001

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef priority_queue<ii> pqii;
typedef priority_queue<int> pqi;
typedef map<ii,int> mii_i;
int n,m,q,deg[MAX_N];
vi people[MAX_N];
vi output[MAX_N];
vi graph[MAX_N];
viii queries;
pqii pq;
pqi top_10;
mii_i el_mapa;
bool seen[MAX_N];

void push_top_output(int index){
    if(output[index].size() >0) return;

    vi temp;
    int counter = 11;
    while(counter-->0 && !top_10.empty()){
        int t = top_10.top(); top_10.pop();
        temp.push_back(t);
        output[index].push_back(-t);
    }

    for(int i=0;i<temp.size();++i){
        top_10.push(temp[i]);
    }
}

void dfs(int start,int u){
    seen[u] = true;
    for(int i=0;i<people[u].size();++i)
        top_10.push(-people[u][i]);

    int x,y;
    x = start;
    y = u;
    if(x > y) swap(x,y);

    mii_i::iterator it = el_mapa.find(ii(x,y));
    if(it!=el_mapa.end()){
        int index = el_mapa[ii(x,y)];
        push_top_output(index);
    }

    for(int i=0;i<graph[u].size();++i){
        int v = graph[u][i];

        if(!seen[v])
            dfs(start, v);
    }
}

int main(){
    int x,y,t;
    scanf("%d %d %d",&n,&m,&q);
    
    for(int i=0;i<n-1;++i){
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    memset(deg, 0, sizeof deg);
    for(int i=0;i<m;++i){
        scanf("%d",&t);
        people[t].push_back(i+1);
    }

    for(int i=0;i<q;++i){
        scanf("%d %d %d",&x,&y,&t);
        queries.push_back(iii(ii(x,y),t));
        ++deg[x];
        ++deg[y];
        if(x > y) swap(x,y);
        el_mapa[ii(x,y)] = i;
    }

    for(int i=0;i<=n;++i){
        if(deg[i]>0)
           pq.push(ii(deg[i], i));
    }

    //proces high degree vertices first
    int d,index;
    while(!pq.empty()){
        d = pq.top().first;
        index = pq.top().second;
        pq.pop();

        /*if(deg[index] <= 0) continue;
        for(int i=0;i<graph[index].size();++i){
            y = graph[index][i];
            --deg[y];
        }*/

        top_10  = pqi();
        memset(seen, false, sizeof seen);
        dfs(index,index);       
    }

    for(int i=0;i<queries.size();++i){
        x = queries[i].first.first;
        y = queries[i].first.second;
        t = queries[i].second;

        if(x > y) swap(x,y);
        int index = el_mapa[ii(x,y)];

        int k = min(t, (int)output[index].size());
        printf("%d ",k);
        for(int j=0;j<k;++j){
            printf("%d ",output[index][j]);
        }
        printf("\n");
    }
    return 0;
}
