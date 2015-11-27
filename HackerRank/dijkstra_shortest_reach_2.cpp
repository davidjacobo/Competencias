#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 3001
#define INF (1<<30)
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii graph[MAX_N];
int dist[MAX_N];

void dijkstra(int source) {
	fill(dist, dist+MAX_N, INF);
	priority_queue<ii> pq;
	dist[source] = 0;
	pq.push(ii(0, source));

	while(!pq.empty()) {
		ii temp = pq.top();
		pq.pop();
		int u = temp.second;

		if(dist[u]!=-temp.first) continue;

		for(int i=0;i<graph[u].size();++i) {
			int v = graph[u][i].first;
			int w = graph[u][i].second;

			int total = dist[u] + w;
			if(total < dist[v]) {
				dist[v] = total;
				pq.push(ii(-total, v));
			}
		}
	}
}

void clean(int v) {
	for(int i=0;i<=v;++i) graph[i].clear();
}

int main() {
	int t;
	int x,y,w;
	int v,e;
	cin>>t;
	while(t--) {
		cin>>v>>e;
		clean(v);
		for(int i=0;i<e;++i) {
			cin>>x>>y>>w;
			graph[x].push_back(ii(y,w));
			graph[y].push_back(ii(x,w));
		}

		cin>>x;
		dijkstra(x);
		for(int i=1;i<=v;++i) {
			if(i==x) continue;

			cout<<((dist[i]==INF)?-1:dist[i])<<" ";
		}
		cout<<endl;
	}
	return 0;
}