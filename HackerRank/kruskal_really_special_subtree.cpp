#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 3001
#define INF (1<<30)

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii, int> ii_i;
typedef vector<ii_i> vii_i;
vii_i edges;
int cmp[MAX_N];

void capture(int& v,int& e,int& s) {
	cin>>v>>e;
	int x,y,w;
	for(int i=0;i<e;++i) {
		cin>>x>>y>>w;
		edges.push_back(ii_i(ii(w,x),y));
	}
	cin>>s;
	sort(edges.begin(), edges.end());
}

int find(int x) {
	if(cmp[x]==x) return x;
	return cmp[x] = find(cmp[x]);
}

int kruskal(int v) {
	for(int i=0;i<=v;++i) cmp[i] = i;

	int ans = 0;
	for(auto edge:edges) {
		int u = edge.first.second;
		int v = edge.second;
		int w = edge.first.first;

		int cmp_x = find(u);
		int cmp_y = find(v);
		if(cmp_x!=cmp_y) {
			cmp[cmp_x] = cmp_y;
			ans+= w;
		}
	}
	return ans;
}

int main() {
	int v,e,s;
	capture(v,e,s);
    cout<<kruskal(v)<<endl;
	return 0;
}