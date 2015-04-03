#include <cstdio>
#include <queue>
#include <cmath>
#include <vector>
#define MAX_V 1001
#define MAX_E 10001
#define INF 2000000000000000L
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> ii_i;
typedef vector<ii_i> vii_i;
typedef long long int lli;

vii_i graph[MAX_V];
int ban_list[MAX_V];
lli distances[MAX_V];

bool block(int t0,int t1,int t2,int t3){
    if(t2 <= t1 && t2>= t0) return true;
    return false;
}

lli custom_dijkstra(int A,int B,int K){
    priority_queue<ii> pq;
    int t0,t1,v,d,tfinish;
    int y,w;
    for(int i=0;i<MAX_V;i++)
        distances[i] = INF;
    distances[A] = K;
    pq.push(ii(-K,A));

    while(!pq.empty()){
        d = -pq.top().first;
        v = pq.top().second;
        pq.pop();
        //printf("analizing:%d time:%d vecinos:%d\n",v,d,(int)graph[v].size());

        if(v==B) return distances[v]-distances[A];
        if(d!=distances[v]) continue;

        for(int i=0;i<graph[v].size();i++){
            y = graph[v][i].first.first;
            w = distances[v] + graph[v][i].first.second;
            t0 = graph[v][i].second;
            t1 = t0+graph[v][i].first.second -1;
            //printf("trying to go:%d distance:%d t0:%d t1:%d",y,w,t0,t1);    

            if(t0==-1){
                //regular dijkstra, no block
                if(w < distances[y]){
                    //printf("reg dijkstra to:%d\n",y);
                    distances[y] = w;
                    pq.push(ii(-w,y));
                }
            } else {
                //[t0, t1] is blocked, if I am blocked, need to wait to t1+1
                tfinish = d+graph[v][i].first.second - 1;
                //[t0, t1] vs [d, tfinish]
                if(block(t0,t1,d,tfinish)){
                    w = t1+1+ graph[v][i].first.second;
                } 

                //regular dijkstra
                if(w < distances[y]){
                    distances[y] = w;
                    pq.push(ii(-w,y));
                }
            }
        }
    }
    return -1;
}

void find_and_fill(int x,int y,int time){
    //block x->y starting from time: time
    for(int i=0;i<graph[x].size();i++){
        if(graph[x][i].first.first==y){
            graph[x][i].second = time;
            //printf("marking x:%d y:%d t0:%d\n",x,y,time);
            return;
        }
    }
}

void label_forth(int i,int N,int time){
    //block x->y from [time, time+graph[x][j].first.second]
    if(i+1==N) return;
    int x = ban_list[i];
    int y = ban_list[i+1];

    for(int j=0;j<graph[x].size();j++){
        if(graph[x][j].first.first==y){
            graph[x][j].second = time;
            //printf("marking x:%d y:%d t0:%d\n",x,y,time);
            find_and_fill(y,x,time);
            label_forth(i+1, N, time+graph[x][j].first.second);
            return;
        }
    }
}

int main(){
    int V,E;
    int A,B,K,G;
    int x,y,d;
    scanf("%d %d",&V,&E);
    scanf("%d %d %d %d",&A,&B,&K,&G);
    for(int i=0;i<G;i++)
        scanf("%d",&ban_list[i]);

    int time0,time1;
    for(int i=0;i<E;i++){
        scanf("%d %d %d",&x,&y,&d);

        graph[x].push_back(ii_i(ii(y,d),-1));
        graph[y].push_back(ii_i(ii(x,d),-1));
    }

    label_forth(0,G,0);
    printf("%lld\n",custom_dijkstra(A,B,K)); 

    return 0;
}
