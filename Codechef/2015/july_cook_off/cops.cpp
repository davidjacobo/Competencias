#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_N 101

using namespace std;
bool houses[MAX_N];

int main(){
    int T, x,y,M,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&M,&x,&y);
        memset(houses, false, sizeof houses);

        for(int i=0;i<M;++i){
            scanf("%d",&t);
            for(int j=max(1, t - x*y); j<=min(100, t + x*y);++j)
                houses[j] = true;
        }

        int ans = 0;
        for(int i=1;i<=100;++i) ans+= houses[i]?0:1;

        printf("%d\n",ans);
    }
    return 0;
}
