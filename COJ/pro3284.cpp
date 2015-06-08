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
            double add = dag[i][j]/max_step;
            for(int step=1;step<=max_step;++step){
                dag[i+1][j+step]+= add;
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
    char line[100];
    int T,n;
    sscanf(gets(line),"%d", &T);

    while(T--){
        sscanf(gets(line), "%d", &n);
        printf("%lf\n", dp(n));
    }
    return 0;
}
