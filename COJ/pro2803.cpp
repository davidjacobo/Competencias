#include <cstdio>
#define MAX_N 11
using namespace std;
char mat[MAX_N][MAX_N];

bool check(int n){
    int add_x[] = {1,-1,0,0};
    int add_y[] = {0,0,1,-1};
    int x,y;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<4;k++){
                x = i+add_x[k];
                y = j+add_y[k];
                if(x<n && y<n && x>=0 && y>=0)
                    if(mat[i][j]==mat[x][y]) return false;
            }
    return true;
}

int main(){
    char line[MAX_N];
    int T, N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%s",line);
            for(int j=0;j<N;j++)
                mat[i][j] = line[j];
        }

        if(check(N)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
