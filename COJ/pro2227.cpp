#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX_N 11
#define INF 2000000000
using namespace std;
int mat[MAX_N][MAX_N], path[MAX_N][MAX_N];

int main(){
    char line[MAX_N];
    int n;
    int x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++){   
        scanf("%s", line);
        for(int j=0;j<n;j++) {
            mat[i][j] = line[j]-'0';
        }
    }
    scanf("%d %d",&x,&y);
    x--; y--;
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) path[i][j] = INF;

    path[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] > mat[i+1][j]) {
                path[i+1][j] = min(path[i][j], path[i+1][j]);
            } else {
                path[i+1][j] = min(mat[i+1][j]-mat[i][j]+path[i][j], path[i+1][j]);
            }

            if(mat[i][j] > mat[i][j+1]) {
                path[i][j+1] = min(path[i][j], path[i][j+1]);
            } else {
                path[i][j+1] = min(mat[i][j+1]-mat[i][j]+path[i][j], path[i][j+1]);
            }
        }
    }

    printf("%d\n",path[x][y]);
    return 0;
}
