#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int len(ll num) {
  int limit = 100000;
  int l = 6;
  while (limit > 0) {
    if (num >= limit)  break;
    --l;
    limit/= 10;
  }
  return l;
}

int main() {
  ll p,q;
  bool printed_anything = false;
  cin>>p>>q;
  for (ll t = p; t <= q; ++t) {
    int l = len(t);
    ll sq = t * t;
    int div = (int)pow(10, l);
    ll right = sq % div;
    ll left = sq / div;
    if (right + left == t)  {
      printed_anything = true;
      cout<<t<<" ";
    }
  }
  if (!printed_anything) cout<<"INVALID RANGE";
  return 0;
}
