#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int T, N, A;
    ll last, K, ans, div;

    scanf("%d",&T);
    while(T--){
        scanf("%d %lld",&N,&K);

        ans = last = 0;
        for(int i=0;i<N;++i){
            scanf("%d",&A);

            if(last > 0){
                if(A > last) {
                    A-= last;
                } else {
                    last= max(last-(A+1), 0LL);
                    continue;
                }
            }

            div = A/K;

            if(div==0) {
                ++ans;
                last = max(K-(A+1), 0LL);
            } else {
                ans+= div;
                if(A%K==0){
                    last = 0;
                } else {
                    ++ans;
                    last = (div+1)*K - (A+1);
                }
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}
