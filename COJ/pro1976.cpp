#include <iostream>
#include <queue>
#include <cmath>
#define MAX_N 1002
#define INF 1000000000
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;

bool blocked[MAX_N][MAX_N];
bool seen[MAX_N][MAX_N];
int distances[MAX_N][MAX_N];
int xgoal, ygoal;

void clean(){
    for(int i=0;i<MAX_N;i++)
        for(int j=0;j<MAX_N;j++){
            distances[i][j] = INF;
            blocked[i][j] = false;
            seen[i][j] = false;
        }
}

bool in_bound(int x,int y){
    if(x<0 || y<0 || x>= MAX_N || y>=MAX_N) return false;
    return true;
}

void dijkstra(){
    int addX[] = {1,-1,0,0};
    int addY[] = {0,0,1,-1};
    priority_queue<iii> pq;
    int x,y,xt,yt,d;
    distances[0][0] = (blocked[0][0])?1:0;
    x = 0; y = 0;
    
    while(!seen[x][y]){
        seen[x][y] = true;
        if(x==xgoal && y==ygoal) return;
    
        for(int i=0;i<4;i++){
            xt = x + addX[i];
            yt = y + addY[i];
            d = distances[x][y] + (blocked[xt][yt])?1:0;
            if(in_bound(xt,yt) && d < distances[xt][yt]){
                distances[xt][yt] = d;
                pq.push(iii(ii(-d,xt),yt));
            }
        }
        
        while(!pq.empty()){
            x = pq.top().first.second;
            y = pq.top().second;
            pq.pop();

            if(!seen[x][y]) break;
        }
    }
}

int main(){
    int v,e;
    int x,y;
    cin>>e>>x>>y;
    xgoal = x-1;
    ygoal = y-1;
    clean();    

    while(e-->0){
        cin>>x>>y;
        x--; y--;
        blocked[x][y] = true;
    }

    dijkstra();
    cout<<distances[xgoal][ygoal]<<endl;
    return 0;
}
