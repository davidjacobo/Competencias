#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define INF (1LL<<60)
#define MAX_N 1000001

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii segments;
ll counter[MAX_N];

int main(){
    int T,N,H;
    int x,y;

    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&H);
        segments.clear();
        for(int i=0;i<N;++i){
            scanf("%d %d",&x,&y);
            segments.push_back(ii(x,y));
        }

        sort(segments.begin(), segments.end());

        priority_queue<int> pq;
        counter[0] = 0;
        for(int i=0,j=0;i<N;++i){
            //pop segments which are not useful for i and so on
            while(!pq.empty()){
                int t = -pq.top();
                if(t < i) pq.pop();
                else break;
            }

            while(j<N && segments[j].first==i)  pq.push(-segments[j++].second);

            //counting and making an integral sum
            counter[i+1] = pq.size() + counter[i];
        }

        ll ans = INF, tunnel = (ll)H*N;
        for(int i=H;i<=N;++i){           
            ans = min(ans, tunnel-(counter[i]-counter[i-H]));
        }

        printf("%lld\n", ans);
    }
}
