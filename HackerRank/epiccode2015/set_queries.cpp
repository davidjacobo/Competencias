#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MOD 1000000009
#define MAX_N 100002

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi sets[MAX_N];
vii gap_list[MAX_N];
int A[MAX_N], heap[MAX_N<<2];
int N,S,M;

int query(int ind,int p,int q,int x,int y){
    if(p==x && q==y) return heap[ind];

    int m = (p+q)>>1;
    int left = ind<<1;
    int right = left + 1;

    if(x > m) {
        return query(right, m+1, q, x, y);
    } else if(y<=m) {
        return query(left, p, m, x, y);
    } else {
        int ans;
        ans = query(left, p, m, x, m);
        ans = (query(right, m+1, q, m+1, y) + ans) % MOD;
        return ans;
    }
}

int query_range(int l,int r){
    return query(1, 1, N, l, r);
}

int query_set(int a){  //proven to be fine
    int l,r;
    int L = gap_list[a][0].first;
    int R = gap_list[a][0].second;

    int ans = query(1, 1, N, L, R);

    for(int i=1;i<gap_list[a].size();++i){
        l = gap_list[a][i].first;
        r = gap_list[a][i].second;
        if(l>r || l>N || r>N || l<1 || r<1) {
            //wtf!
            continue;
        } else if(l==r){
            ans = (ans - A[l]) % MOD;
        } else {
            ans = (ans - query(1, 1, N, l, r)) % MOD;
        }
        while(ans<0) ans+= MOD;
    }

    return ans;
}

void update(int ind,int p,int q,int x,int add){
    if(p==q){
        heap[ind] = A[p];
        return;
    } else {
        int m = (p+q)>>1;
        int left = ind<<1;
        int right = left+1;

        heap[ind] = (heap[ind] + add) % MOD;

        if(x > m){
            update(right, m+1, q, x, add);
        } else {
            update(left, p, m, x, add);
        }
    }
}

void update_range(int l,int r,int t){
    for(int i=l;i<=r;++i){
        A[i] = (A[i] + t) % MOD;
        update(1, 1, N, i, t);
    }
}

void update_set(int a,int t){
    for(int i=0;i<sets[a].size();++i){
        A[sets[a][i]] = (A[sets[a][i]] + t) % MOD;
        update(1, 1, N, sets[a][i], t);
    }
}

void turn_set_to_gap_list(int a) {
    gap_list[a].clear();
    if(sets[a].size()==0) return;
    if(sets[a].size()>1)
        sort(sets[a].begin(), sets[a].end());
    int l,r,L,R;

    L = sets[a][0];
    R = sets[a][sets[a].size()-1];
    gap_list[a].push_back(ii(L,R));     

    for(int i=0;i<sets[a].size()-1;++i){
        if(sets[a][i]==(sets[a][i+1]-1)){
                continue;
        } else {
            gap_list[a].push_back(ii(sets[a][i]+1, sets[a][i+1]-1));
        }
    }
}

int main(){
    int len, t, a, l, r, op;
    scanf("%d %d %d",&N,&S,&M);
    memset(A, 0, sizeof A);

    for(int i=1;i<=S;++i){
        scanf("%d",&len);

        sets[i].clear();
        for(int j=0;j<len;++j){
            scanf("%d",&t);
            sets[i].push_back(t);
        }
        turn_set_to_gap_list(i);
    }

    for(int i=0;i<M;++i){
        scanf("%d",&op);
        if(op==1){
            scanf("%d %d",&a,&t);
            update_set(a,t);
        } else if(op==2) {
            scanf("%d",&a);
            printf("%d\n",query_set(a));
        } else if(op==3){
            scanf("%d %d %d",&l,&r,&t);
            update_range(l,r,t);
        } else {
            scanf("%d %d",&l,&r);
            printf("%d\n",query_range(l,r));
        }
    }

    return 0;
}
