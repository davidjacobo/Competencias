#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define MAX_N 101
#define INV -1

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii, int> ii_i;
typedef vector<ii_i> vii_i;

char maze[MAX_N][MAX_N][MAX_N];
int dist[MAX_N][MAX_N][MAX_N];
int xe, ye, ze;
vii_i vertices;

void Capture(int M,int N,int F) {
  char input[MAX_N];
  memset(dist, INV, sizeof dist);
  vertices.clear();

  for(int k=0;k<F;++k) {
    for(int i=0;i<M;++i) {
      scanf("%s", input);
      for(int j=0;j<N;++j) {
        maze[i][j][k] = input[j];
        if (input[j] == 'S') {
          dist[i][j][k] = 0;
          vertices.push_back(ii_i(ii(i,j), k));
        } else if (input[j] == 'E') {
          xe = i;
          ye = j;
          ze = k;
        }
      }
    }
  }
}

bool inside_limits(int X,int Y,int Z,int x,int y,int z) {
  if(x<0 || y<0 || z<0) return false;
  if(x>=X || y>=Y || z>=Z) return false;
  return true;
}

int BFS(int M,int N,int F) {
  int add_x[] = {1,-1,0,0,0,0};
  int add_y[] = {0,0,1,-1,0,0};
  int add_z[] = {0,0,0,0,1,-1};
  int x,y,z;
  int xt,yt,zt,neigh;
  for(int i=0;i<vertices.size();++i) {
    ii_i triple = vertices[i];
    ii pair = triple.first;
    x = pair.first; y = pair.second; z = triple.second;
    int new_dist = dist[x][y][z] + 1;
    neigh = 4;
    if(maze[x][y][z]=='-') neigh = 6;    

    for (int k=0; k<neigh;++k) {
      xt = x + add_x[k];
      yt = y + add_y[k];
      zt = z + add_z[k];
      if(inside_limits(M,N,F,xt,yt,zt)) {
        if(k<4) {
          if(maze[xt][yt][zt]!='#' && dist[xt][yt][zt]==INV) {
            dist[xt][yt][zt] = new_dist;
            vertices.push_back(ii_i(ii(xt,yt), zt));
          }
        } else {
          if(maze[xt][yt][zt]=='-' && dist[xt][yt][zt]==INV) {
            dist[xt][yt][zt] = new_dist;
            vertices.push_back(ii_i(ii(xt,yt), zt));
          }
        }
      }
    }
  }
  return dist[xe][ye][ze];
}

int main() {
  int M,N,F;
  while(scanf("%d %d %d", &M, &N, &F)!=EOF) {
    if(M==0 && N==0 && F==0) break;
    Capture(M,N,F);
    printf("%d\n", BFS(M,N,F));
  }
  return 0;
}

