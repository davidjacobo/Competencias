#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main(){
    int T, N, D,t;
    vi vec;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&D);
        vec.clear();
        for(int i=0;i<N;++i){
            scanf("%d",&t);
            vec.push_back(t);
        }

        sort(vec.begin(), vec.end());

        ll ans = 0;
        for(int i=N-1;i>0;--i){
            if(vec[i]-vec[i-1] < D) {
                ans+= (vec[i] + vec[i-1]);
                --i;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
