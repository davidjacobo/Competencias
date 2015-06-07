#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX_N 5001

using namespace std;
double dag[MAX_N][MAX_N];

double dp(int n){
    memset(dag, 0, sizeof dag);
    dag[0][0] = 1.0;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int max_step = min(10, n-j);
            for(int step=1;step<=max_step;++step){
                dag[i+1][j+step]+= (dag[i][j]/(max_step));
            }
        }
    }

    double ans = 0.0;
    for(int i=0;i<=n;++i){
        ans+= dag[i][n]*i;
    }

    return ans;
}

int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%lf\n", dp(n));
    }
    return 0;
}
