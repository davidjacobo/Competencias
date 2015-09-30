#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 19
#define MAX_MASK (1<<19)
#define INV -1

using namespace std;
typedef long long ll;
ll tab[MAX_MASK][MAX_N], sol;
int mat[MAX_N][MAX_N], dish[MAX_N];
int target;

int count_bits(int n,int m){
    int ans = 0;
    for(int i=0;i<m;++i){
        if((n&(1<<i))!=0) ++ans;
    }
    return ans;
}

ll pick(int mask,int dishes,int last_dish){
    if(count_bits(mask,dishes)==dishes) return dish[last_dish];
    if(last_dish!=INV && tab[mask][last_dish]!=INV) return tab[mask][last_dish];

    ll maximo = 0;
    for(int i=0;i<dishes;++i){
        if((mask&(1<<i))==0){
            ll t = pick((mask|(1<<i)),dishes,i);
            if(last_dish!=INV)
               t+= mat[last_dish][i] + dish[last_dish];

            if(t > maximo) maximo = t;
        }
    }
    if(count_bits(mask,dishes)==target) sol = max(sol, maximo);

    return tab[mask][last_dish] = maximo;
}

int main(){
    int n,m,k;
    int x,y,w;
    scanf("%d %d %d",&n,&m,&k);
    target = n-m+1;

    memset(tab, INV, sizeof tab);
    memset(mat, 0, sizeof mat);

    sol = 0;
    for(int i=0;i<n;++i){
        scanf("%d",&dish[i]);
        sol = max(sol, ll(dish[i]));
    }
    for(int i=0;i<k;++i){
        scanf("%d %d %d",&x,&y,&w);
        --x; --y;
        mat[x][y] = w;
    }

    if(m==1){
        printf("%lld",sol);
    }else{
        pick(0, n, -1);
        printf("%lld\n", sol);
    }

    return 0;
}
