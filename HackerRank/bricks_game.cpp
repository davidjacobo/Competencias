#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX_N 100001
#define INV -1
#define INF (1LL<<60)
using namespace std;
typedef long long ll;
ll tab[2][MAX_N], sums[MAX_N];
int arr[MAX_N];

ll dp(int n,int player) {
    if(n<=0) return 0;
    if(tab[player][n]!=INV) return tab[player][n];
    
    ll ans, temp, sum = 0;
    ans = INV;
    
    for(int i=1;i<=min(3,n);++i) {
        sum+= arr[n-i+1];
        temp = sums[n] - dp(n-i, 1-player);
        //temp+= sum;
        
        if(temp>ans) ans = temp;
    }
    //cout<<"player "<<player<<" can sum up to: "<<ans<<" on: "<<n<<endl;
   
    return tab[player][n] = ans;
}

int main() {
    int t;
    int n;
    cin>>t;
    while(t--) {
        cin>>n;
        memset(tab, INV, sizeof tab);
        for(int i=0;i<n;++i) {
            cin>>arr[n-i];
        }
        
        sums[0] = 0;
        for(int i=1;i<=n;++i) {
            sums[i] = sums[i-1]+arr[i];
            //cout<<"s: "<<i<<" "<<sums[i]<<endl;
        }
        
        cout<<dp(n,1)<<endl;
    }
    return 0;
}