#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF (1<<30)
#define MAX_N 101

using namespace std;
int dis[MAX_N], next_v[MAX_N];

void capture(int n) {
	int x,y;
	while(n--) {
		cin>>x>>y;
		next_v[x-1] = y-1;
	}
}

int solve() {
	queue<int> q;
	fill(dis, dis+MAX_N, INF);
	dis[0] = 0;	
	q.push(0);
	int u,v;

	while(!q.empty()) {
		u = q.front();
		q.pop();
		if(next_v[u]!=INF && dis[next_v[u]]==INF) {
			dis[next_v[u]] = dis[u];
			q.push(next_v[u]);
		} 
        
        if(next_v[u]!=INF) continue;

		for(int i=1;i<7;++i) {
			v = u+i;
			if(v > 99) break;

			if(dis[v] == INF) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}

	if(dis[99]==INF) return -1;
	return dis[99];
}

int main() {
	int t, n;
	cin>>t;
	while(t--) {
		fill(next_v, next_v+MAX_N, INF);
		cin>>n;
		capture(n);
		cin>>n;
		capture(n);

		cout<<solve()<<endl;
	}
	return 0;
}