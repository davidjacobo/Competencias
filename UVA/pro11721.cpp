#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_N 1001
#define MAX_M 2001
#define INF 1000000000

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
vii graph[MAX_N];

int distances[MAX_N];
bool seen[MAX_N];
vector<int> output;

void dfs(int v){
    output.push_back(v);
    seen[v] = true;
    for(int i=0;i<graph[v].size();i++){
        int y = graph[v][i].first;
        if(!seen[y]) dfs(y);
    }
}

void bellman_ford(int n){
    int i,j,k,y,w;

    for(i=0;i<n-1;i++){
        for(j=0;j<n;j++){
            for(k=0;k<graph[j].size();k++){
                y = graph[j][k].first;
                w = graph[j][k].second;
                if(distances[y] > distances[j] + w){
                    distances[y] = distances[j] + w;
                }
            }
        }
    }

    for(j=0;j<n;j++){
        for(k=0;k<graph[j].size();k++){
            y = graph[j][k].first;
            w = graph[j][k].second;
            if(distances[y] > distances[j] + w) {
                distances[y] = distances[j] + w;
                if(!seen[y]) dfs(y);
                //everything reachable from y is afected by the negative cycle
            }
        }
    }
}

void clean(int n){
    output.clear();
    for(int i=0;i<n;i++){
        graph[i].clear();
        seen[i] = false;
        distances[i] = INF;
    }
}

int main(){
    int t,v,e;
    int x,y,w;
    int counter = 1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&v,&e);
        clean(v);

        while(e--){
            scanf("%d %d %d",&x,&y,&w);
            graph[y].push_back(ii(x,w));
        }

        bellman_ford(v);

        printf("Case %d:",counter++);
        if(output.size()){
            sort(output.begin(), output.end());
            for(int i=0;i<output.size();i++)
                printf(" %d",output[i]);
            printf("\n");
        } else {
            printf(" impossible\n");
        }
    }
    return 0;
}
