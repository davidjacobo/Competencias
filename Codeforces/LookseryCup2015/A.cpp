#include <iostream>
#include <cstring>
#define MAX_N 51

using namespace std;
char mat[MAX_N][MAX_N];
int m,n;

bool check(int x,int y){
    bool seen[26];
    memset(seen, false, sizeof seen);

    seen[mat[x][y]-'a'] = true;
    seen[mat[x][y-1]-'a'] = true;
    seen[mat[x-1][y]-'a'] = true;
    seen[mat[x-1][y-1]-'a'] = true;

    if(seen['f'-'a'] && seen[0] && seen['c'-'a'] && seen['e'-'a']) return true;
    return false;
}

int main(){
    char line[MAX_N];
    cin>>m>>n;
    for(int i=0;i<m;++i){
        cin>>line;
        for(int j=0;j<n;++j){
            mat[i][j] = line[j];
        }
    }

    int ans = 0;
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(check(i,j)) ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}
