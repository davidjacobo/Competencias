#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 100001

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

vii friends;
ll integral_sum[MAX_N];

int main(){
    int n,d,m,f;
    cin>>n>>d;
    for(int i=0;i<n;++i){
        cin>>m>>f;
        friends.push_back(ii(m,f));
    }

    sort(friends.begin(), friends.end());

    integral_sum[0] = 0;
    for(int i=1;i<=n;++i){
        integral_sum[i] = friends[i-1].second + integral_sum[i-1];
    }

    int init,end = 0;
    int j = 0;
    ll ans = 0;
    for(int i=0;i<n;++i){
        init = friends[i].first;
        end = init+d;
        while(j<n && friends[j].first<end){
            ++j;
        }

        ans = max(ans, integral_sum[j]-integral_sum[i]);
    }

    cout<<ans<<endl;
    return 0;
}
