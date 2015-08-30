#include <queue>
#include <cstdio>

using namespace std;

int main(){
    priority_queue<int>  pq;
    int N, t, limak;

    scanf("%d %d",&N,&limak);
    for(int i=1;i<N;++i){
        scanf("%d",&t);
        pq.push(t);
    }

    int ans = 0;
    while(limak <= pq.top()) {
        t = pq.top(), pq.pop();
        ++limak;
        --t;
        ++ans;
        pq.push(t);
    }

    printf("%d",ans);
}
