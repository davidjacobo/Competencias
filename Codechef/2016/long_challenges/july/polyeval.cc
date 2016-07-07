#include <cmath>
#include <iostream>
#define MAX_N 1001
#define MOD 786433

using namespace std;
typedef long long ll;

int main() {
  int N,Q,coef[MAX_N];
  cin>>N;
  for(int i=0;i<=N;++i) {
    cin>>coef[i]; 
  }

  cin>>Q;
  while(Q--) {
    int temp;
    cin>>temp;
    ll base = 1;
    ll total = 0;
    int i = 0;
    while(i <= N) {
      total  = (total + base*coef[i]) % MOD;
      base = (base * temp) % MOD;
      ++i;
    }
    cout<<total<<endl;
  }
  return 0;
}
