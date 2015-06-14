#include <cstdio>
#define MAX_N 21
using namespace std;
bool A[MAX_N][MAX_N], X[MAX_N][MAX_N];

void build_x(int num,int N){
    for(int i=0;i<N;++i)
        X[i][i] = false;

    bool a,b;
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            a = ((num&(1<<i))!=0)?true:false;
            b = ((num&(1<<j))!=0)?true:false;
            X[i][j] = X[j][i] = (a!=b)?true:false;
        }
    }
}

bool only_ones(int N){
    bool t;
    for(int i=0;i<N;++i){
        for(int j=i;j<N;++j){
            t = (!A[i][j] || (A[i][j] && X[i][j]));
            if(!t) return false;
        }
    }
    return true;
}

int count_zeros(int N){
    bool t;
    int ans = 0;
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            t = (!X[i][j] || (A[i][j] && X[i][j]));
            if(!t) ++ans;
        }
    }

    ans<<=1;
    for(int i=0;i<N;++i){
        t = (!X[i][i] || (A[i][i] && X[i][i]));
        if(!t) ++ans;
    }
    return ans;
}

int main(){
    int num, T, N,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                scanf("%d",&t);
                if(t==1) A[i][j] = true;
                else A[i][j] = false;
            }
        }

        int ans = -1, Y;
        for(num=0;num<(1<<N);++num){
            build_x(num, N);
            if(only_ones(N)){
                t = count_zeros(N);
                if(t > ans) {
                    ans = t;
                    Y = num;
                }
            }
        }

        if(-1==ans) {
            printf("-1\n");
        } else {
            bool first = true;
            for(int i=0;i<N;++i){
                if(!first) printf(" ");
                first = false;
                printf("%d", (Y&(1<<i))?1:0);
            }
            printf("\n");
        }
    }
}
