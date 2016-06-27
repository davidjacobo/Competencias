#include <iostream>
#include <algorithm>
#include <cstring>

constexpr int kMaxM = 10001;
constexpr int INV = -1;

using namespace std;

int main() {
  int T,M,N,t,prices[kMaxM], buffer[kMaxM];
  cin>>T;
  while(T--) {
    cin>>M>>N;
    memset(prices, INV, sizeof prices);
    for(int i = 1; i <= N; ++i) {
      cin>>t;
      buffer[i] = t; 
      if (prices[t] == INV)
        prices[t] = i;
    }

    bool done = false;
    for(int i = 1; i <= N; ++i) {
      t = M - buffer[i];
      if (t > 0 && prices[t] != INV && prices[t] != i) {
        cout<<min(prices[t], i)<<" "<<max(prices[t], i)<<endl;
        done = true;
        break;
      }
    }
  }
  return 0;
 }
