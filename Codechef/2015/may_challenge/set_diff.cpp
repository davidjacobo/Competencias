#include <iostream>
#include <algorithm>
#include <cmath>
#define MOD 1000000007
#define MAX_N 100001

using namespace std;
typedef long long ll;

int arr[MAX_N];

int main(){
    int T, N, ans;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;++i){
            cin>>arr[i];
        }

        sort(arr, arr+N);

        ll pot = 2;
        int min, max;
        min = max = 0;
        for(int i=N-2,j=1;i>=0;--i,++j){
            max = (max + arr[j]*(pot-1))%MOD;
            min = (min + arr[i]*(pot-1))%MOD;
            pot = (pot<<1)%MOD;
        }

        ans = (max-min)%MOD;
        while(ans<0) ans+= MOD;

        cout<<ans<<endl;
    }
    return 0;
}
