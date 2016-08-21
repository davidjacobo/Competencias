#include <iostream>
#include <cstring>
#include <vector>
#define MAX_N 100001
#define INF 1<<30

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> ii_i;
typedef vector<ii_i> vii_i;

vii_i pairs;
bool storage[MAX_N];

void capture(int V,int E,int k) {
  memset(storage, false, sizeof(storage));
  int x,y,d;
  for(int i=0;i<E;++i) {
    cin>>x>>y>>d;
    pairs.push_back(ii_i(ii(x,y), d));
  }

  while(k--) {
    cin>>y;
    storage[y] = true;
  }
}

int solve(int E) {
  int minimal = INF;
  for(int i=0;i<E;++i) {
    int x = pairs[i].first.first;
    int y = pairs[i].first.second;
    int d = pairs[i].second;

    if(storage[x] != storage[y]) {
      minimal = min(minimal, d);
    }
  }

  return (minimal == INF) ? -1 : minimal;
}

int main() {
  int v,e,k;
  cin>>v>>e>>k;
  capture(v,e,k);
  cout<<solve(e);
  return 0;
}
