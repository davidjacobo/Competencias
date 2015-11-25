#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX_N 401
#define INF (1<<30)

using namespace std;
typedef vector<int> vi;
bool graph[MAX_N][MAX_N], back[MAX_N][MAX_N];
int dis[MAX_N];

void bfs(int v,bool g[MAX_N][MAX_N]) {
	int x = 1;
	for(int i=0;i<=MAX_N;++i) dis[i] = INF;
	queue<int> q;
	q.push(x);
	dis[1] = 0;

	while(!q.empty()) {
		int u = q.front();
		//cout<<"dist to "<<u<<" = "<<dis[u]<<endl;
		q.pop();

		for(int i=1;i<=v;++i) {
			//cout<<"conection between "<<u<<" to "<<i<<" "<<g[u][i]<<" "<<dis[i]<<endl;
			if(g[u][i] && dis[i]==INF) {
				dis[i] = dis[u]+1;
				q.push(i);
			}
		}
	}

	if(dis[v]==INF) dis[v] = -1;

}

int main() {
	int v,e;
	int x,y;
	cin>>v>>e;
	memset(back, true, sizeof back);
	memset(graph, false, sizeof graph);
	for(int i=0;i<e;++i) {
		cin>>x>>y;
		graph[x][y] = graph[y][x] = true;
		back[x][y] = back[y][x] = false;
 	}

 	if(graph[1][v]) {
 		bfs(v,back);
 	} else {
 		bfs(v,graph);
 	}
 	cout<<dis[v];
}