#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_N 3001
#define INF (1<<30)
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vii graph[MAX_N];
int dist[MAX_N];
bool used[MAX_N];

void capture(int& v,int& e,int& s) {
	int x,y,w;
	cin>>v>>e;
	for(int i=0;i<e;++i) {
		cin>>x>>y>>w;
		graph[x].push_back(ii(y,w));
		graph[y].push_back(ii(x,w));
	}
	cin>>s;
}

int prim(int v,int e,int s) {
	priority_queue<ii> pq;
	fill(dist, dist+MAX_N, INF);
	fill(used, used+MAX_N, false);
	dist[s] = 0;
	pq.push(ii(0, s));
	int ans = 0;

	while(!pq.empty()) {
		ii temp = pq.top();
		pq.pop();

		int u = temp.second;
		used[u]|= true;
		if(dist[u]!=-temp.first) continue;
		ans+= -temp.first;

		for(int i=0;i<graph[u].size();++i) {
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			//Prim doesnt actually gives a fuck about 
			//the acumulated sum of the branch
			int total = w;
			if(dist[v] > total && !used[v]) {
				dist[v] = total;
				pq.push(ii(-total, v));
			}
		}
	}
	return ans;
}

int main() {
	int v,e,s;
	capture(v,e,s);
	cout<<prim(v,e,s)<<endl;
	return 0;
}