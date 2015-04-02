#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX_N 100002
using namespace std;

typedef long long int lli;
char cow[] = " COW";
char word[MAX_N];

lli dp(int len){
    lli mat[4][len];
    memset(mat, 0, 4*len*sizeof(lli));
    for(int i=1;i<len;i++)
        mat[1][i] = mat[1][i-1] + ((word[i]=='C')?1:0);

    for(int i=2;i<4;i++){
        int counter = 0;
        for(int j=1;j<len;j++){
            if(word[j]==cow[i]){
                counter++;
                mat[i][j] = mat[i-1][j-1] + mat[i][j-1];
            }
            else
                mat[i][j] = mat[i][j-1];
        }
    }

    return mat[3][len-1];
}

int main(){
    int len;
    word[0] = ' ';
    scanf("%d %s", &len, &word[1]);
    printf("%lld\n",dp(len+1));
    return 0;
}
