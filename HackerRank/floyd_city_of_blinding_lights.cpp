#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_V 401
#define INF (1<<29)
using namespace std;
int dist[MAX_V][MAX_V];

void capture(int& v,int& e) {
    for(int i=0;i<MAX_V;++i)    for(int j=0;j<MAX_V;++j) dist[i][j] = (i==j)?0:INF;
    cin>>v>>e;
    int x,y,w;
 
    for(int i=0;i<e;++i) {
        cin>>x>>y>>w;
        --x; --y;
        dist[x][y] = w;
    }
}

void floyd(int v) {
    int d;
    for(int k=0;k<v;++k) {
        for(int i=0;i<v;++i) {
            for(int j=0;j<v;++j) {
                d = dist[i][k] + dist[k][j];
                if(d < dist[i][j]) {
                    dist[i][j] = d;
                }
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int v,e;
    int x,y;
    capture(v,e);
    floyd(v);
    cin>>v;
    while(v--) {
        cin>>x>>y;
        --x; --y;
        cout<<((dist[x][y]==INF)?-1:dist[x][y])<<endl;
    }
    return 0;
}
