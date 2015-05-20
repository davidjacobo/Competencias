#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_V 300001
#define MAX_E 300001
#define INF 10000000000000000L

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> ii_i;
typedef pair<ii,ii> ii_ii;
typedef vector<ii_i> vii_i;
typedef vector<ii_ii> vii_ii;
typedef long long ll;

vii_i graph[MAX_V];
vector<int> output;
int V,E, edges[MAX_E], parent[MAX_V];
ll distances[MAX_V];

ll dijkstra(int source){
    priority_queue<ii_i> pq;
    ll w, D, ans;
    int e, y, start = source;

    for(int i=1;i<=V;++i)
        distances[i] = INF;
    distances[source] = 0;
    parent[source] = 0;
    ans = 0;

    pq.push(ii_i(ii(0,source),0));

    while(!pq.empty()){
        source = pq.top().first.second;
        w = -pq.top().first.first;
        e = pq.top().second;
        pq.pop();

        if(distances[source]!= w) continue;
    
        for(int i=0;i<graph[source].size();++i){
            D = graph[source][i].first.first + distances[source];
            y = graph[source][i].first.second;
            e = graph[source][i].second;

            if(D < distances[y]){
                parent[y] = e;
                distances[y] = D;
                pq.push(ii_i(ii(-D, y), e));
            } else if(D==distances[y] && graph[source][i].first.first < edges[parent[y]]){
                parent[y] = e;
            }
        }
    }

    for(int i=1;i<=V;++i){
        if(i!=start){
            ans+= edges[parent[i]];   
            output.push_back(parent[i]);
        }
    }
    
    return ans;
}

int main(){
    int x,y,t;
    cin>>V>>E;
    edges[0] = 0;
    for(int i=1;i<=E;++i){
        cin>>x>>y>>t;
        graph[x].push_back(ii_i(ii(t,y),i));
        graph[y].push_back(ii_i(ii(t,x),i));
        edges[i] = t;
    }
    cin>>t;
    cout<<dijkstra(t)<<endl;
    sort(output.begin(), output.end());
    for(int i=0;i<output.size();++i){
        cout<<output[i]<<" ";
    }
    return 0;
}
