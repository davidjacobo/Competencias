#include <cstdio>
#include <cstring>
#define MAX_N 200002
#define MOD 1000000007

using namespace std;
int N,Q,sums[MAX_N], heap[MAX_N<<2], A[MAX_N];

void pre_calc(){
    memset(A, 0, sizeof A);

    sums[0] = 0;
    for(int i=1;i<MAX_N;++i){
        sums[i] = (sums[i-1]+(i<<1))%MOD;
    }
}

int query(int id,int p,int q,int x,int y){
    if(p>q || x>y) return 0;

    if(p==x && q==y) {
        return heap[id];
    } else {
        int ans = 0, m = (p+q)>>1;
        int left = id<<1;
        int right = left+1;

        if(x > m){
            return query(right, m+1, q, x, y);
        } else if(y <= m){
            return query(left, p, m, x, y);
        } else {
            ans = query(left, p, m, x, m);
            ans+= query(right, m+1, q, m+1, y);
            return ans % MOD;
        }
    }
}

void update_branch(int id,int p,int q,int x,int change){
    if(p==q){
        heap[id] = A[p];
        return;
    } else {
        int left = id<<1;
        int right = left+1;
        int m = (p+q)>>1;

        heap[id] = (heap[id]+change+MOD)%MOD;

        if(x > m) {
            update_branch(right, m+1, q, x, change);
        } else {
            update_branch(left, p, m, x, change);
        }
    }
}

void update(int x,int y){
    for(int i=x,j=1;i<=y;++j,++i){
       A[i] = (A[i]+sums[j])%MOD;
       update_branch(1, 1, N, i, sums[j]);
    }
}

int main(){
    scanf("%d %d", &N,&Q);
    memset(sums, 0, sizeof sums);
    pre_calc();
    int x,y,op;

    for(int i=0;i<Q;++i){
        scanf("%d %d %d", &op,&x,&y);
        if(op==1){
            update(x,y);
        } else {
            printf("%d\n", (query(1,1,N,x,y)+MOD)%MOD);
        }
    }
    return 0;
}
