#include <cstdio>
#include <algorithm>
#define MAX_N 1000000001
#define MAX_M 100001
using namespace std;

int h[MAX_M], day[MAX_M];

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d %d",&day[i],&h[i]);
    }

    bool fail = false;
    int max_climb = h[0];
    for(int i=1;i<M;i++){
        int step = day[i]-day[i-1];
        int diff = abs(h[i]-h[i-1]);
        max_climb = max(max_climb, max(h[i], max(h[i],h[i-1])+(step-diff)/2));

        if(diff > step) {
            fail = true;
        }
    }

    if(fail){ 
        printf("IMPOSSIBLE");
    } else {
        if(day[0]!=1){
            int step = day[0]-1;
            max_climb = max(max_climb, h[0]+step);
        }
        if(day[M-1]!=N){
            int step = N-day[M-1];
            max_climb = max(max_climb, h[M-1]+step);
        }

        printf("%d",max_climb);
    }
    return 0;
}
