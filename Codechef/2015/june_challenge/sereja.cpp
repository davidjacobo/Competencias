#include <cstdio>
#include <cstring>
#define MAX_N 101

using namespace std;
int mat[MAX_N][MAX_N];

int main(){
    int T,N,M, rep[1001];

    scanf("%d",&T);
    while(T--){
        memset(rep, 0, sizeof rep);

        scanf("%d %d",&N,&M);
        for(int i=0;i<M;++i){
            for(int j=0;j<N;++j){
                scanf("%d",&mat[i][j]);
                ++rep[mat[i][j]];
            }
        }

        for(int i=1;i<=1000;++i)    rep[i]>>=1;

        printf("%d\n",(M*N)>>1);
        for(int i=0;i<M;++i){
            for(int j=0;j<N;++j){
                if(rep[mat[i][j]]){
                    printf("%d %d %d %d\n",i+1,j+1,i+1,j+1);
                    --rep[mat[i][j]];
                }
            }
        }
    }
}
