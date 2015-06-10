#include <cstdio>
#include <cstring>
#define MAX_N 2001
#define MOD 1000000000
using namespace std;
typedef long long ll;
int ways[MAX_N][MAX_N];

void build_ways(){
    for(int i=0;i<MAX_N;++i)    ways[i][0] = 0;
    for(int j=0;j<MAX_N;++j)    ways[0][j] = ways[j][1] =  1;

    for(int i=1;i<MAX_N;++i) 
        for(int j=2;j<MAX_N;++j)
            ways[i][j] = (ways[i-1][j] + ways[i][j-1]) % MOD;
}

int solve(int N,int M){
    int last[M+1], nuevo[M+1];
    ll ans = 0;
    for(int i=0;i<=M;++i){
        last[i] = ways[i][M];
        ans = (ans + last[i]) % MOD;
    }

    if(N==1) return ans;

    ll sum_row;
    for(int i=1;i<N;++i){
        sum_row = 0;
        for(int j=0;j<=M;++j){
            sum_row= (last[j] + sum_row) % MOD;
            nuevo[j] = (sum_row * ways[j][M]) % MOD;
        }

        for(int j=0;j<=M;++j)
            last[j] = nuevo[j];
    }

    ans = 0;
    for(int j=0;j<=M;++j)
        ans = (ans + nuevo[j]) % MOD;
    return (ans + MOD) % MOD;
}

int main(){
    int T,N,M;

    build_ways();
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&M);
        printf("%d\n", solve(N,M));
    }
    return 0;
}
