#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_N 51
#define INF (1<<30)

using namespace std;
int cross[MAX_N][2], other[MAX_N];

int main(){
    int n;
    cin>>n;
    memset(cross, 0, sizeof cross);
    memset(other, 0, sizeof other);
    for(int i=0;i<n-1;++i){
        cin>>cross[i+2][0];
        cross[i+2][0] += cross[i+1][0];
    }
    for(int i=0;i<n-1;++i){
        cin>>cross[i+2][1];
        cross[i+2][1] += cross[i+1][1];
    }

    for(int i=0;i<n;++i){
        cin>>other[i+1];
    }
    
    int ans = INF;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            ans = min(ans, cross[i][0]+cross[j][0]+cross[n][1]-cross[i][1]+cross[n][1]-cross[j][1]+other[i]+other[j]);
            ans = min(ans, cross[j][0]+cross[i][0]+cross[n][1]-cross[j][1]+cross[n][1]-cross[i][1]+other[j]+other[i]);
            //cout<<"temp min "<<i<<" "<<j<<" "<<ans<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
