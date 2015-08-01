#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int T,N,M;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&M);
        int div = M/N;
        int total = div*N;

        if(total == M){
            --div;
            total = div*N;
        }
        M-= total;

        if((total&1)!=0){
            --M;
            --N;
        }

        if((M&1)==0){
            printf("%d %d\n",(int)(N-ceil(M/2.0)+1),div);
        } else {
            printf("%d %d\n",(M>>1)+1,div);
        }
    }

}
