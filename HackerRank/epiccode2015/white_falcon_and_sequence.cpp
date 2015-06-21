#include <cstdio>
#include <algorithm>
#define MAX_N 3001
#define INF (1LL<<62)

using namespace std;
typedef long long ll;

ll sums[MAX_N][MAX_N];
int nums[MAX_N];

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d",&nums[i]);

    ll max_sum = max(0,nums[1]), diag = 0;
    for(int i=N-3,j=1;i>=0;--i,++j){
        for(int k=j-1;k<=j;++k){
            int y = k;
            int x = i;
            diag = 0;
            while(x>=0 && y>=0){
                diag+= (ll)nums[y]*nums[N-x-1];
                max_sum = max(diag, max_sum);
                if(diag < 0)    diag = 0;
                --x; --y;
            }
        }
    }

    printf("%lld\n", max_sum);
    return 0;
}
