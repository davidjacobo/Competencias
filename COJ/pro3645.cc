#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX_N 1001
#define INV -1
using namespace std;

int indexes[MAX_N];

int formula(int a,int c,int m,int x) {
  return (x*a + c) % m;
}

void solve(int a,int c,int m,int x_0) {
  memset(indexes, INV, sizeof indexes);
  int current_index = 1;
  indexes[x_0] = current_index++;
   
  int x = formula(a,c,m,x_0);
  while (indexes[x] == INV) {
    indexes[x] = current_index++;
    x = formula(a,c,m,x);
  }

  --current_index;
  if (current_index == m) {
    printf("YES ");
  } else {
    printf("NO ");
  } 
  int cycle = current_index - indexes[x] + 1;
  printf("%d %d %d\n", current_index, (current_index-cycle), cycle);
}

int main() {
  int c,a,m,x_0;
  while(scanf("%d",&a)!=EOF) {
    scanf("%d %d %d",&c,&m,&x_0);
    solve(a,c,m,x_0);
  }
  return 0;
}
