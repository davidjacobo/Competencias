#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_V 4001
#define INF (1<<30)
using namespace std;

bool graph[MAX_V][MAX_V];
int counter[MAX_V];

int main(){
    int V,E;
    int x,y;
    scanf("%d %d",&V,&E);
    memset(graph, false, sizeof graph);
    memset(counter, 0, sizeof counter);

    for(int i=0;i<E;++i){
        scanf("%d %d",&x,&y);
        graph[x][y] = graph[y][x] = true;
        ++counter[x];
        ++counter[y];
    }

    int ans = INF;
    for(int i=1;i<=V-2;++i){
        if(counter[i]<2) continue;
        for(int j=i+1;j<=V-1;++j){
            if(counter[j]<2 || !graph[i][j]) continue;
            for(int k=j+1;k<=V;++k){
                if(graph[i][j] && graph[i][k] && graph[j][k])
                    ans = min(ans, counter[i]+counter[j]+counter[k]);
            }
        }
    }

    
    printf("%d",((ans==INF)?-1:ans-6));
    return 0;
}
