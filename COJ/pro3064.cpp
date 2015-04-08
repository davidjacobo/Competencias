#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 100001
using namespace std;
int parent[MAX_N], peso[MAX_N], seen[MAX_N];
bool amigo[MAX_N];
int ans;

int calc_distance(int v,int branch_weight){
    if(seen[v] || 1==v){ 
        ans+= branch_weight;
        return seen[v];
    }
  
    seen[v] = calc_distance(parent[v], branch_weight+peso[v])+peso[v];
    return seen[v];
}

int main(){
    int N,F,i;
    int x,y,w;
    scanf("%d %d",&N,&F);
    memset(peso, 0, MAX_N*sizeof(int));
    memset(amigo, 0, MAX_N*sizeof(bool));
    memset(seen, 0, MAX_N*sizeof(bool));

    i = N-1;
    while(i--){
        scanf("%d %d %d",&x,&y,&w);
        parent[y] = x;
        peso[y] = w;
    }

    i = F;
    while(i--){
        scanf("%d",&x);
        amigo[x] = true;
    }

    seen[1] = 0;
    peso[1] = 0;
    int max_branch = 0;
    ans = 0;

    for(int i=1;i<=N;i++)
        if(amigo[i] && !seen[i])
            max_branch = max(max_branch,calc_distance(i,0));

    //ok, if seen[i]==1, we have a leaf, calc dist to root
    printf("%d\n",ans-max_branch);
    return 0;
}
