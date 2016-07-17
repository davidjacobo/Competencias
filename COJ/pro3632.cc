#include <cstdio>
#include <cstring>
#define MAX_N 100001
#define DIGITS 10
#define INV -1

using namespace std;
int arr[MAX_N], last_index[MAX_N][DIGITS];

void Init(int n) {
  memset(last_index, INV, sizeof last_index);
  for(int j=1;j<=n;++j) {
    for(int i=0;i<DIGITS;++i) {
      last_index[j][i] = last_index[j-1][i];
      if (i==arr[j]) last_index[j][i] = j;
    }
  }
}

int solve(int l,int r) {
  int ans = 0;
  for(int i=0;i<DIGITS;++i) if(last_index[r][i] >= l) ++ans;
  return ans;
}

int main() {
  int n;
  while(scanf("%d",&n)!=EOF) {
    for(int i=1;i<=n;++i)
      scanf("%d",&arr[i]);
    Init(n);

    int q, l, r;
    scanf("%d", &q);
    while(q--) {
      scanf("%d %d", &l, &r);
      printf("%d\n", solve(l,r));
    }
  }
  return 0;
}
