#include <cstdio>
#include <queue>
#include <cstring>
#define MAX_N 101

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int pots[MAX_N];

int main(){
    int n,k,t;
    ll ans = 0;
    memset(pots, 0, sizeof pots);
    priority_queue<ii> q;

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&t);
        ans+= (t/10);

        if(t%10==0){
            ++pots[t];
        }else{
            q.push(ii(t%10, t));
        }
    }

    while(!q.empty()){
        ii par = q.top();
        q.pop();
        int num = par.second;
        int dig = par.first;

        if(k >= 10-dig){
            k-= (10-dig);
            ++ans;
            pots[num+(10-dig)]++;
        }
    }

    for(int i=0;i<100;i+=10){
        while(k>=10 && pots[i]>0){
            --pots[i];
            ++pots[i+10];
            ++ans;
            k-= 10;
        }
    }

    printf("%lld",ans);
    return 0;
}
