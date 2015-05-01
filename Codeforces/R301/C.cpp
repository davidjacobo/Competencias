#include <iostream>
#include <queue>
#include <cstring>
#define MAX_N 502

using namespace std;

typedef pair<int,int> ii;
bool cracked[MAX_N][MAX_N];

bool valid(int x,int y,int m,int n){
    if(x>=m || y>=n || x<0 || y<0) return false;
    return true;
}

int count_non_cracked_neigh(int x,int y,int m,int n){
    int addX[] = {0,0,1,-1};
    int addY[] = {1,-1,0,0};
    int ans = 0;
    for(int k=0;k<4;k++){
        int x1= x+addX[k];
        int y1= y+addY[k];
        if(valid(x1,y1,m,n) && !cracked[x1][y1]) ++ans;
    }   
    return ans;
}

bool bfs(int x0,int y0,int x1,int y1,int m,int n){
    int addX[] = {0,0,1,-1};
    int addY[] = {1,-1,0,0};

    queue<ii> q;
    q.push(ii(x0,y0));

    int x,y;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        if(x==x1 && y==y1) return true;
        q.pop();

        for(int k=0;k<4;k++){
            int xt = x+addX[k];
            int yt = y+addY[k];
            if(valid(xt,yt,m,n) && (!cracked[xt][yt] || (xt==x1 && yt==y1))){
                q.push(ii(xt,yt));
                cracked[xt][yt] = true;
            }
        }
    }

    return false;
}

int main(){
    char line[MAX_N];
    int n,m;
    int x0,y0, x1,y1;
    cin>>m>>n;
   
    for(int i=0;i<m;i++){
        cin>>line;
        for(int j=0;j<n;j++){
            cracked[i][j] = (line[j]=='X')?true:false;
        }
    }
    cin>>x0>>y0;
    cin>>x1>>y1;
    x0--; y0--; x1--; y1--;
    cracked[x0][y0] = false;
    int counter = count_non_cracked_neigh(x1,y1,m,n);

    if(x0==x1 && y0==y1) {
        if(counter>0)
            cout<<"YES";
        else
            cout<<"NO";
    }else if(cracked[x1][y1]){
        if(bfs(x0,y0,x1,y1,m,n))
            cout<<"YES";
        else
            cout<<"NO";
    } else if(!cracked[x1][y1]){
        if(counter>=2 && bfs(x0,y0,x1,y1,m,n))
            cout<<"YES";
        else
            cout<<"NO";
    } else {
        cout<<"NO";
    }
    
    return 0;
}
