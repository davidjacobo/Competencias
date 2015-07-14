#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX_N 100001
#define MAX_HEAP (MAX_N<<2)
#define MAX_K 501
#define INF (1<<30)

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int heap[MAX_HEAP], A[MAX_N], cost[MAX_N]; 
int K, N, Q;

void update(int ind,int p,int q,int x,int y,int val){
    val = min(val, heap[ind]);

    if(p==x && q==y){
        heap[ind] = val;
    } else {
        int l = ind<<1;
        int r = l+1;
        int m = (p+q)>>1;

        if(x > m) {
            update( r, m+1, q, x, y, val);
        } else if(y<=m) {
            update( l, p, m, x, y, val);
        } else {
            update( l, p, m, x, m, val);
            update( r, m+1, q, m+1, y, val);
        }
    }
}

int spread(int ind,int p,int q,int val){
    if(p==q){
        cost[p] = min(heap[ind],val);
    } else {
        int l = ind<<1;
        int r = l+1;
        int m = (p+q)>>1;

        val = min(val, heap[ind]);
        spread(l, p, m, val);
        spread(r, m+1, q, val);
    }
}

ll dp(){
    vii vec;
    ll nuevo[MAX_K], viejo[MAX_K];
    ll ans = 0;
    for(int i=0;i<N;++i){
        ans+= A[i];
        A[i]*= -1;
        if(A[i] > 0 && cost[i]!=INF){
            vec.push_back(ii(A[i], cost[i]));
        }
    }

    sort(vec.begin(), vec.end());

    memset(nuevo, -1, sizeof nuevo);
    memset(viejo, -1, sizeof viejo);

    viejo[0] = 0;
    for(int i=0;i<vec.size();++i){
        for(int j=0;j<=K;++j){
            nuevo[j] = max(nuevo[j],viejo[j]);

            if(viejo[j]!=-1 && j+vec[i].second<=K){
                nuevo[j+vec[i].second] = max(nuevo[j+vec[i].second], viejo[j]+vec[i].first);
            }
        }

        for(int j=0;j<=K;++j)
            viejo[j] = nuevo[j];
    }

    ll maximo = -INF;
    for(int i=0;i<=K;++i){
        if(nuevo[i] > maximo)   maximo = nuevo[i];
    }

    return ans + maximo;
}

void clean(){
    for(int i=0;i<((N<<2)+1);++i)
        heap[i] = INF;
    for(int i=0;i<N;++i)
        cost[i] = INF;
}

int main(){
    int T;
    int x,y,val;

    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&N,&K,&Q);
        clean();

        for(int i=0;i<N;++i){
            scanf("%d",&A[i]);
        }

        while(Q--){
            scanf("%d %d %d",&x,&y,&val);
            --x;    --y;
            update(1,0,N-1,x,y,val);
        }

        spread(1, 0, N-1,INF);
        printf("%lld\n", dp());   
    }
    return 0;
}
