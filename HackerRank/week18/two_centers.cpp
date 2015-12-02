#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAX_V 5001
#define INV -1
#define INF (1<<30)

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vi graph[MAX_V];
vii edges;
ii ban;
bool seen[MAX_V];
int dist[MAX_V];

void capture(int& v) {
	cin>>v;
	int x,y;
	for(int i=0;i<v-1;++i) {
		cin>>x>>y;
		--x; --y;
		edges.push_back(ii(x,y));
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
}

void dfs(int u) {
	seen[u] = true;

	for(int i=0;i<graph[u].size();++i) {
		int v = graph[u][i];
		if((u==ban.first && v==ban.second) || (v==ban.first && u==ban.second)) continue;

		if(!seen[v]) dfs(v);
	}
}

int calc_diameter(int u) {
	fill(dist, dist+MAX_V, INF);
	dist[u] = 0;
	queue<int> q;
	q.push(u);

	while(!q.empty()) {
		u = q.front();
		q.pop();

		for(int i=0;i<graph[u].size();++i) {
			int v = graph[u][i];
			if((u==ban.first && v==ban.second ||
				u==ban.second && v==ban.first)) 
				continue;

			if(dist[v]==INF) {
				dist[v] = dist[u] +1;
				q.push(v);
			}
		}
	}

	return u;
}

int both_diameters(int v) {
	fill(seen, seen+MAX_V, false);
    int x = ban.first;
    int y = ban.second;
    
	x = dist[calc_diameter(calc_diameter(x))];
	y = dist[calc_diameter(calc_diameter(y))];

	return ceil(max(x,y)/2.0);
}

int solve(int v) {
	int ans = INF;
	for(int i=0;i<v-1;++i) {
		ban.first = edges[i].first;
		ban.second = edges[i].second;

		ans = min(ans, both_diameters(v));
	}
	return ans;
}

int main() {
	int v;
	capture(v);
	cout<<solve(v);
	return 0;
}