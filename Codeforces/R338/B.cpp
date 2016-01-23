#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_V 100001

using namespace std;

typedef vector<int> vi;
typedef long long ll;
vi graph[MAX_V];
int v,e, indegree[MAX_V], dis[MAX_V];

void capture(int e) {
	fill(indegree, indegree+MAX_V, 0);
	int x,y;
	while(e--) {
		cin>>x>>y;
		if(x > y) swap(x,y);
		graph[x].push_back(y);
		indegree[y]++;
		indegree[x]++;
	}
}

ll solve(int v) {
	fill(dis, dis+MAX_V, 1);
	ll ans = 0;
	for(int i=1;i<=v;++i) {
		int u = i;
		ans = max(ans, (ll)indegree[u]*dis[u]);

		for(int j=0;j<graph[i].size();++j) {
			int v = graph[i][j];
			dis[v] = max(dis[v], dis[u]+1);
		}
	}
	return ans;
}

int main() {
	cin>>v>>e;
	capture(e);

	cout<<solve(v)<<endl;
	return 0;
}