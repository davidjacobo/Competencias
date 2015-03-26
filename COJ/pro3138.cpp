#include <cstdio>
#define MAX_N 100
using namespace std;
int A[MAX_N][MAX_N];

int main(){
    int T,M,N;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d",&M,&N);
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&A[j][i]);

        for(int i=0;i<N;i++){
            bool first = true;
            for(int j=0;j<M;j++){
                if(!first) printf(" ");
                first = false;
                printf("%d",A[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
