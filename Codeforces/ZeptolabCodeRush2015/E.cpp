#include <cstdio>
#include <algorithm>
#include <map>
#define MAX_N 1000001
#define INF 2000000001
using namespace std;
typedef long long int lli;
typedef map<lli, int> mlli_i;

lli sums[MAX_N<<1];
int p,q,index,arr[MAX_N],next[MAX_N],min_T;

void min_interval(int N,lli k){
    int j=1,len;
    min_T = INF;
    for(int i=1;i<=N;i++){
        while(sums[j]-sums[i-1]<=k){
            j++;
        }
        //printf("sum:%lld i:%d j%d\n",sums[j]-sums[i-1],i,j);
        len = j-i;
        next[i-1] = (j-1)%N;
        //printf("i:%d next:%d\n",i-1,next[i-1]);
        if(len<min_T){
            min_T = len;
            p = i-1;
            q = (j-1)%N;
        }
    }
}

int count_ranges(int i,lli k,int N,int min_intervals){
    int counter = 2;
    int low = next[i], up = next[next[i]];
    bool cycle = false;
    while(true){
        if(up > low) {
            if(low<=i && up>=i) return counter;
        } else {    
            //modular
            if((-1<=i && up>=i) || (low<=i && N>=i)) return counter;
        }
        //printf("here:%d to:%d\n",low,up);
        counter++;
        low = up;
        up = next[up];
    }
    return counter;
}

int main(){
    int N,Q;
    int min_intervals;
    lli k;
    scanf("%d %d",&N,&Q);
    sums[0] = 0;
    mlli_i el_mapa;
    for(int i=0;i<N;i++){    
        scanf("%d",&arr[i]);
        sums[(i+1)+N] = sums[i+1] = arr[i];
    }

    for(int i=1;i<=(N<<1);i++)
        sums[i] += sums[i-1];

    while(Q--){
        scanf("%lld",&k);
        if(k >= sums[N]){
            printf("1\n");
        } else {
            if(el_mapa.count(k)==0){
                min_interval(N,k);
                //printf("counted: %d %d",p,q);
                min_intervals = N/min_T+1;
                for(int i=p;i<=q;i++){
                    if(i<0) break;
                    min_intervals = min(min_intervals, count_ranges(i,k,N,min_intervals));
                }
                el_mapa[k] = min_intervals;
            } else {
                min_intervals = el_mapa[k];
            }
            printf("%d\n",min_intervals);
        }
    }
    return 0;
}
