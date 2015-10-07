#include <iostream>
#include <cstring>
#define MOD 1000000007
#define MAX_N 1001

using namespace std;
typedef long long ll;
int c1[MAX_N],c2[MAX_N];
ll rep[MAX_N], mat[MAX_N][MAX_N];

void solve(int c){
    ll sum, row_sum;
    for(int level=1;level<=c;++level){
        sum = row_sum = 0;
        for(int i=1;i<MAX_N;++i){
            mat[i][level] = (rep[i]*sum)%MOD;
            row_sum = (row_sum + mat[i][level])%MOD;

            sum = (sum + mat[i][level-1])%MOD;
        }

        if(level!=1) cout<<" ";
        cout<<row_sum;
    }
}

int main(){
    int n,m,c;
    cin>>n>>m>>c;
    memset(c1, 0, sizeof c1);
    memset(c2, 0, sizeof c2);
    memset(rep, 0, sizeof rep);
    memset(mat, 0, sizeof mat);

    int t;
    for(int i=0;i<n;++i){
        cin>>t;
        ++c1[t];
    }
    for(int i=0;i<m;++i){
        cin>>t;
        ++c2[t];
    }
    for(int i=0;i<MAX_N;++i){
        mat[i][0] = rep[i] = (ll)c1[i]*c2[i];
    }

    solve(c);
    return 0;
}
