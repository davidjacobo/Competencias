#include <iostream>
#include <vector>
#include <cstring>
#define MAX_DIM 101
#define INF 1<<30

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii, int> ii_i;
typedef vector<ii_i> vii_i;
vii_i don_vector;

int dist[MAX_DIM][MAX_DIM];
bool blocked[MAX_DIM][MAX_DIM];
bool seen_k1[MAX_DIM][MAX_DIM];
bool seen_k2[MAX_DIM][MAX_DIM];

void capture(int N,int M) {
  memset(seen_k1, false, sizeof seen_k1);
  memset(seen_k2, false, sizeof seen_k2);
  int input;
  for(int i=1;i<=N;++i) {
    for(int j=1;j<=M;++j) {
      dist[i][j] = INF;
      cin>>input;
      if(input==1) blocked[i][j] = true;
      else blocked[i][j] = false;
    }
  } 
}

int diagonal(int x,int y,int counter,int N,int M,int add_x,int add_y,int base_dist,int robot) {
  while(counter-->0) {
    if(x > 0 && x <= N && y > 0 && y <= M) {
      if(robot==1 && seen_k2[x][y]) return dist[x][y] + 1;
      if(robot==2 && seen_k1[x][y]) return dist[x][y] + 1;
      if(dist[x][y] ==INF && !blocked[x][y]) {
        dist[x][y] = base_dist + 1;
        don_vector.push_back(ii_i(ii(x,y), robot));
      }   
      if(robot==1) seen_k1[x][y] = true;
      if(robot==2) seen_k2[x][y] = true;
    }
    x+= add_x;
    y+= add_y;
  }
  return -1;
} 

int flood(int x,int y,int reach,int N,int M,int robot) {
  int ret = -1;
  for(int z=1;z<=reach;++z) {
    ret = diagonal(x,y+z,z,N,M,1,-1,dist[x][y],robot);
    if(ret!=-1) return ret;
    ret = diagonal(x,y-z,z,N,M,-1,1,dist[x][y],robot);
    if(ret!=-1) return ret;
    ret = diagonal(x+z,y,z,N,M,-1,-1,dist[x][y],robot);
    if(ret!=-1) return ret;
    ret = diagonal(x-z,y,z,N,M,1,1,dist[x][y],robot);
    if(ret!=-1) return ret;
  }
  return ret;
}

int solve(int N, int M, int K1, int K2) {
  if(M==1) return 0;
  // Pre-work needed
  don_vector.clear();
  seen_k1[1][1] = true;
  seen_k2[1][M] = true;
  don_vector.push_back(ii_i(ii(1,1),1));
  don_vector.push_back(ii_i(ii(1,M),2));
  dist[1][1] = dist[1][M] = 0;

  // Ok let's pick the candidates on the vector 1 by 1, flooding the reach
  // of the initial robots with K1 and K2 correspondingly.
  for(int i=0;i<don_vector.size();++i) {
    ii_i triple = don_vector[i];
    int x = triple.first.first;
    int y = triple.first.second;
    int z = triple.second;

    if(z==1) {
      int t = flood(x,y,K1,N,M,z);
      if(t!=-1) return t;
    } else {
      int t = flood(x,y,K2,N,M,z);
      if(t!=-1) return t;
    }
  }

  return -1;
}

int main() {
  int T, N,M,K1,K2;
  cin>>T;
  while(T--) {
    cin>>N>>M>>K1>>K2;
    capture(N,M);
    cout<<solve(N,M,K1,K2)<<endl;
  }
  return 0;
}
