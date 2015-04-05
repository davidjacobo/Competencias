#include <cstdio>
#include <algorithm>
#define MAX_N 100001
using namespace std;
typedef long long int lli;
lli sums[MAX_N];

int main(){
    int T;
    int N,Q;
    int x,y;
    bool first = true;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&Q);
        sums[0] = 0;
        for(int i=1;i<=N;i++){
            scanf("%d",&x);
            sums[i] = x + sums[i-1];
        }

        if(!first) printf("\n");
        first = false;

        while(Q--){
            scanf("%d %d",&x,&y);
            if(x>y) swap(x,y);
            x++;
            y++;
            if(x>N) {
                printf("0\n");
            } else {
                if(y>N) 
                    y = N;
                printf("%lld\n",sums[y]-sums[x-1]);
            }
        }
    }
    return 0;
}
