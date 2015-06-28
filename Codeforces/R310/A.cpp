#include <cstdio>
#define MAX_N 100001

using namespace std;

int mat[MAX_N];

int main(){
    int N,k,m,ans,parts,rem,j,len;
    scanf("%d %d",&N,&k);
    ans = parts = 0;

    for(int i=0;i<k;++i){
        scanf("%d",&m);
        scanf("%d",&mat[0]);

        if(mat[0]==1) {
            j = 2;
            while(j<=m){
                scanf("%d",&mat[j-1]);
                if(j!=mat[j-1]) break;
                ++j;
            }
            len = j-1;
            while(++j<=m) scanf("%d",&mat[j-1]);
            ans+= (m-len);
        } else {
            for(int j=1;j<m;j++)
                scanf("%d",&mat[j]);
            ans+= (m-1);
        }
    } 
    printf("%d\n",(ans+N-len));
    return 0;
}
