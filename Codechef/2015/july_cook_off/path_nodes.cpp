#include <vector>
#include <algorithm>
#include <cstdio>
#define MAX_N 100001
#define INVALID -1

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi graph[MAX_N];
int parent[MAX_N], depth[MAX_N];
bool inset[MAX_N];

void clear(int N){
    for(int i=1;i<=N;++i){
        graph[i].clear();
        depth[i] = INVALID;
        inset[i] = false;
    }
}

void dfs(int u){
    for(int i=0;i<graph[u].size();++i){
        if(INVALID == depth[graph[u][i]]){
            depth[graph[u][i]] = depth[u]+1;
            parent[graph[u][i]] = u;
            dfs(graph[u][i]);
        }
    }
}

int main(){
    vii vset;
    int T,N,Q,K,x,y;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        clear(N);

        for(int i=1;i<N;++i){
            scanf("%d %d",&x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        //Pick any node and make it the root!
        depth[1] = 0;
        parent[1] = INVALID;
        dfs(1);

        scanf("%d",&Q);
        while(Q--){
            scanf("%d",&K);
            vset.clear();

            for(int i=0;i<K;++i){
                scanf("%d",&x);
                inset[x] = true;
                vset.push_back(ii(depth[x],x));
            }

            sort(vset.begin(), vset.end());

            //3 or more vertices with the same depth = FAIL
            bool skip = false;
            for(int i=0;i<K-2 && !skip;++i){
                if(vset[i].first == vset[i+2].first) {
                    printf("No\n");
                    for(int j=0;j<K;++j)
                        inset[vset[j].second] = false;
                    skip = true;
                    break;
                }
            }

            if(skip)    continue;

            //Pick the 2 deepest vertices, and start backtracking
            //til the root
            x = vset[K-1].second;
            y = vset[K-2].second;
            int remaining = K-2;
            int ind = K-3;

            while(1){
                while(depth[x] > depth[y]){
                    x = parent[x];
                    if(inset[x]){
                        inset[x] = false;
                        --remaining;
                    }
                }

                while(depth[y] > depth[x]){
                    y = parent[y];
                    if(inset[y]){
                        inset[y] = false;
                        --remaining;
                    }
                }

                //x and y are at the same level
                if(x == y) {
                    //same vertex, same branch!
                    //let's pick another vertex, hopefully on another
                    //branch!!
                    if(ind>=0) {
                        y = vset[ind--].second;
                        continue; 
                    } else {
                        //There is only one branch
                        printf("Yes\n");
                        for(int i=0;i<K;++i)    inset[vset[i].second] = false;
                        break;
                    }
                } else {
                    //same depth, 2 branches!!, let's go LCA
                    while(x!=y) {
                        x = parent[x];
                        y = parent[y];

                        if(inset[x]){
                            inset[x] = false;
                            --remaining;
                        }
                        if(inset[y]){
                            inset[y] = false;
                            --remaining;
                        }
                    }

                    //LCA is X, print and break;
                    if(remaining==0) {
                        printf("Yes\n");
                    } else {
                        printf("No\n");
                    }

                    for(int i=0;i<K;++i)
                        inset[vset[i].second] = false;
                    break;
                }
            }
        }
    }
    return 0;
}
