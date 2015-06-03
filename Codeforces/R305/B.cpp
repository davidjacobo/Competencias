#include <iostream>
#include <cstring>
#define MAX_N 502

using namespace std;
int m,n,q,mat[MAX_N][MAX_N];

int column_sum(int i){
    int ans = 0, maximo = 0;
    for(int j=0;j<n;++j){
        if(mat[i][j]) ++ans;
        else{
            if(ans > maximo) 
                maximo = ans;
            ans = 0;
        }
    }
    if(ans > maximo) maximo = ans;

    return maximo;
}

void sums(){
    for(int i=0;i<m;++i){
        mat[i][n] = column_sum(i);
    }
}

int max_row(){
    int ans = 0;
    for(int i=0;i<m;++i)
        if(mat[i][n]>ans) ans = mat[i][n];
    return ans;
}

int main(){
    int t;
    cin>>m>>n>>q;
    memset(mat, 0, sizeof mat);
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>mat[i][j];
        }
    }

    sums();

    int x,y;
    while(q--){
        cin>>x>>y;
        --x;   --y;
        mat[x][y] = 1-mat[x][y];
        mat[x][n] = column_sum(x);
        cout<<max_row()<<endl;
    }
    return 0;
}
