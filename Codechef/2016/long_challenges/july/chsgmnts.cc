#include <iostream>
#include <set>
#define MAX_N 1001

using namespace std;
typedef long long ll;

int main() {
  int T,N,arr[MAX_N];
  cin>>T;
  while(T--) {
    cin>>N;
    for(int i=0;i<N;++i) cin>>arr[i];

    ll ans = 0;
    for(int i=0;i<N;++i) {
      set<int> don_set;
      for(int j=i;j<N-1;++j) {
        don_set.insert(arr[j]);
        int count = 0;
        for(int k=j+1;k<N;++k) {
          if(don_set.find(arr[k])!=don_set.end()) {
            ans += (count*(count+1))/2;
            count = 0;
          } else {
            ++count;
          }
        }
        if(count!=0) ans+= (count*(count+1))/2;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
