#include <cstdio>
#include <algorithm>
#define MAX_N 100001
#define INF (1<<30)

using namespace std;
int t[MAX_N], timetodie[MAX_N];

void build(){
    for(int i=0;i<MAX_N;++i)    timetodie[i] = INF;
}

int main(){
    int n,ans;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&t[i]);
    }

    ans = 1;
    //We are only certain of the most left and most right blocks to die at t=1
    timetodie[0] = timetodie[n-1] = 1;
    for(int i=1;i<n-1;++i){
        timetodie[i] = min(timetodie[i-1]+1, min(t[i]-1,min(t[i-1],t[i+1]))+1);
    }

    for(int i=n-2;i>0;--i){
        timetodie[i] = min(timetodie[i] , min(timetodie[i+1]+1, min(t[i]-1,min(t[i-1],t[i+1]))+1));
        ans = max(ans, timetodie[i]);
    }
    printf("%d", ans);
    return 0;
}
