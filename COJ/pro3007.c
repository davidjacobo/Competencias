#include <stdio.h>
#include <stdlib.h>
char mat[8][8];
int screwed;

void dfs(int i,int j,int dx,int dy){
    if(i<0 || i>=8 || j<0 || j>=8) return;
    if(mat[i][j]=='*') screwed = 1;
    if(screwed) return;

    i+=dx;
    j+=dy;
    dfs(i,j,dx,dy);
}

int main(){
    char *p = (char *)malloc(9);
    int i,j,queens = 0;

    for(i=0;i<8;i++){
        scanf("%s", p);
        for(j=0;j<8;j++)
            mat[i][j] = p[j];
    }

    screwed = 0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(mat[i][j]=='*') {
                queens++;
                dfs(i+1,j+1, 1, 1);
                dfs(i+1,j-1, 1,-1);
                dfs(i-1,j+1,-1, 1);
                dfs(i-1,j-1,-1,-1);
                dfs(i+1,j  , 1, 0);
                dfs(i-1,j  ,-1, 0);
                dfs(i  ,j+1, 0, 1);
                dfs(i  ,j-1, 0,-1);
            }
        }
    }

    if(screwed || queens!=8) printf("invalid\n");
    else printf("valid\n");

    return 0;
}
