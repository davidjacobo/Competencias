#include <cstdio>
#include <cmath>
#define MAX_N 1000001

using namespace std;
typedef long long ll;
typedef long double ld;
ld powers_combined[MAX_N];

void Init() {
  powers_combined[0] = 0;
  powers_combined[1] = 1;
  for(int i = 2; i < MAX_N; ++i) {
    powers_combined[i] = powers_combined[i-2] + pow(i, 2.0);
  }
}

ld solve(int n) {
  ld ans = 0.0;
  ans = powers_combined[2*n-1-n] + powers_combined[n-1];
  ans = sqrt(ans/(n-1));
  return ans;
}

int main() {
  int n;
  Init();
  scanf("%d", &n);
  while(n) {
    printf("%.20Lf\n", solve(n));
    scanf("%d", &n);
  }
  return 0;
}
