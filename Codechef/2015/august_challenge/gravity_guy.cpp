#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF (1<<30)
#define MAX_N 200002

using namespace std;

int distances[2][MAX_N];

void init(int n){
    for(int i=0;i<=n;++i){
        distances[0][i] = distances[1][i] = INF;
    }

    distances[0][n] = distances[1][n] = 0;
}

int main(){
    char line[2][MAX_N];
    int T,len;
    scanf("%d",&T);
    while(T--){
        scanf("%s %s",&line[0][0],&line[1][0]);
        len = strlen(line[0]);

        init(len);

        for(int i=len-1;i>=0;--i){
            for(int j=0;j<2;++j){
                if(line[j][i]=='#') continue;

                distances[j][i] = min(INF,min(distances[j][i+1] , distances[1-j][i+1]+1));
            }
        }

        if(distances[0][0]==INF && distances[1][0]==INF){
            printf("No\n");
        } else if(distances[0][0] < distances[1][0]){
            printf("Yes\n%d\n",distances[0][0]);
        } else {
            printf("Yes\n%d\n",distances[1][0]);
        }
    }
    return 0;
}
