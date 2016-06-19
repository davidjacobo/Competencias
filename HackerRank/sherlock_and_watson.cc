#include <iostream>

using namespace std;
static const int kMaxN = 100001;

int main() {
  int n,k,q,t,arr[kMaxN];
  cin>>n>>k>>q;
  k%= n;
  for(int i = 0; i < n; ++i) {
    cin>>t;
    arr[i] = t;
  }

  while(q--) {
    cin>>t;
    cout<<(arr[(t-k+n)%n])<<endl;
  }
  return 0;
}
