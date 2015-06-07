#include <iostream>
#include <cstring>
#define MAX_N 101

using namespace std;

int counter[MAX_N][MAX_N];
bool mat[MAX_N][MAX_N];
int m,n;

int main(){
    char line[MAX_N], t;

    cin>>m>>n;
    for(int i=0;i<m;++i){
        cin>>line;
        for(int j=0;j<n;++j){
            t = line[j];
            if(t=='W') mat[i][j] = true;
            else mat[i][j] = false;
        }
    }

    memset(counter, 0, sizeof counter);

    int ans = 0;
    for(int i=m-1;i>=0;--i){
        for(int j=n-1;j>=0;--j){
            if(mat[i][j] && counter[i][j]==1) continue;
            if(!mat[i][j] && counter[i][j]==-1) continue;

            if(mat[i][j]) {
                ++ans;
                int k = 1 - counter[i][j];
                for(int a=0;a<=i;++a) for(int b=0;b<=j;++b) counter[a][b]+= k;
            } else {
                ++ans;
                int k = -1 - counter[i][j];
                for(int a=0;a<=i;++a) for(int b=0;b<=j;++b) counter[a][b]+= k;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
