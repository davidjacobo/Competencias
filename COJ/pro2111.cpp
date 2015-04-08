#include <cstdio>
#include <cstring>
#define MAX_N 10001
#define MAX_M 256
using namespace std;
short table[MAX_M][MAX_N];

void dp(int n){
    for(int i=1;i<MAX_M;i++)
        for(int j=1;j<=n;j++)
            table[i][j]+= table[i][j-1];
}

int query(int low,int up){
    int counter = 0;
    for(int i=1;i<MAX_M;i++)
        counter+= (table[i][up]-table[i][low-1]>0)?1:0;
    return counter;
}

int main(){
    int n,k,t,x,y;
    scanf("%d %d",&n,&k);
    memset(table,0,MAX_M*MAX_N*sizeof(short));
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        table[t][i+1]=1;
    }

    dp(n);
    while(k--){
        scanf("%d %d",&x,&y);
        printf("%d\n",query(x,y));
    }
    return 0;
}
