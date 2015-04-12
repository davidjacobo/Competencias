#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    priority_queue<int> pq;
    int T, D, temp, time, MAX_TIME, ans,counter=1;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&D);
        pq = priority_queue<int>();   
    
        while(D--){
            scanf("%d",&temp);
            pq.push(temp);
        }

        time = 0;
        ans = MAX_TIME = pq.top();

        while(1){
            temp = pq.top();
            pq.pop();

            if(temp==1) break;

            pq.push(temp>>1);
            pq.push(ceil(temp/2.0));

            ans = min(pq.top()+time+1, ans);
            time++;
        }

        printf("Case #%d: %d\n",counter++,ans);
    }
    return 0;
}
