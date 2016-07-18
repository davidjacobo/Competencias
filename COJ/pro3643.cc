#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 100001
#define INV -1

using namespace std;
typedef long long ll;
int dist[MAX_N];

void Init() {
  vector<int> don_vector;
  memset(dist, INV, sizeof dist);
  int i = 1;
  ll sum = 1;
  while(sum < MAX_N) {
    dist[(int)sum] = 1;  
    don_vector.push_back((int)sum);
    ++i;
    sum+= i;
  } 

  for(int i=0;i<don_vector.size();++i)
    for(int j=i;j<don_vector.size();++j) {
      int sum = don_vector[i] + don_vector[j];
      if (sum > MAX_N) break;
      if (dist[sum]==INV)
        dist[don_vector[i]+don_vector[j]] = 2;
    }
}

int main() {
  int n;
  Init();
  while(scanf("%d", &n)!=EOF) {
    if(dist[n]==INV) {
      printf("%d\n", 3);
    } else {
      printf("%d\n", dist[n]);
    }
  }
  return 0;
}
