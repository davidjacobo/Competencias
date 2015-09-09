#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int T, N,M,ones,ans,gaps;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&M,&N);
        ones = 0;
        priority_queue<int> q;
        for(int i=0;i<N;++i){
            scanf("%d",&ans);
            if(ans==1)  ++ones;
            else q.push(-ans);
        }

        ans = 0;
        gaps = N-(ones+1);
        if(gaps <= ones){
            ones-= (gaps-1);
            ans= gaps + (ones>>1);
        }else{
            ans+= ones;
            N= (N-(ones<<1)-1);

            while(!q.empty()){
                gaps = -q.top();
                q.pop();
                if(gaps>=N) break;
                N-= (gaps+1);
                ans+= gaps;
            }
            ans+= max(0,N);
        }

        printf("%d\n",ans);
    }
    return 0;
}
