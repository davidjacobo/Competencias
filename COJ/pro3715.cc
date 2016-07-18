#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_V 1001
#define MAX_E 100001
#define INV -1

using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> ii_i;
typedef vector<ii_i> vii_i;

int component[MAX_V];
vii_i edges;

int find(int x) {
  if(x == component[x]) return x;
  return component[x] = find(component[x]);
}

void Capture(int E) {
  int x, y, w;
  while(E--) {
    scanf("%d %d %d", &x, &y, &w);
    edges.push_back(ii_i(ii(w, x), y));
  } 
}

void Init(int V) {
  edges.clear();
  for(int i=0;i<V;++i) component[i] = i;
}

void Solve(int V) {
  sort(edges.begin(), edges.end());
  int comps = V;
  int ans = INV;

  for (int i = edges.size() - 1; i > -1 && comps > 1; --i) {
    ii_i triple = edges[i];
    ii pair = triple.first;
    int w = pair.first;
    int x = pair.second;
    int y = triple.second;

    int cmp_x = find(x);
    int cmp_y = find(y);
    if(cmp_x != cmp_y) {
      component[cmp_x] = cmp_y;
      --comps;
      ans = w;
    } 
  }

  if (comps > 1) {
    printf("IMPOSSIBLE\n");
  } else {
    printf("%d\n", ans);
  }
}

int main() {
  int V,E;
  scanf("%d %d", &V, &E);
  while(V!=0 && E!=0) {
    Init(V);
    Capture(E);
    Solve(V);
    
    scanf("%d %d", &V, &E);
  }
  return 0;
}
