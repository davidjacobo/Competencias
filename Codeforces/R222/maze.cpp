#include <iostream>
#include <cstring>
#include <string>
#define MAX_N 502
#define EMPTY 0
#define WALL 1
#define BLOCK 2
using namespace std;
int mat[MAX_N][MAX_N];
int add_x[] = {1,-1,0,0};
int add_y[] = {0,0,1,-1};
int ttl;

void dfs(int x,int y) {
	--ttl;
	if(ttl < 0) return;
	mat[x][y] = BLOCK;

	for(int i=0;i<4;++i) {
		int x1 = x+add_x[i];	
		int y1 = y+add_y[i];

		if(mat[x1][y1]==EMPTY) dfs(x1,y1);
	}
}	

void print(int m,int n) {
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			if(mat[i][j]==WALL) {
				cout<<"#";
			} else if(mat[i][j]==EMPTY) {
				cout<<"X";
			} else {
				cout<<".";
			}
		}
		cout<<endl;
	}
}

int main() {
	string line;
	int m,n,k;
	int x,y;
	cin>>m>>n>>k;
	memset(mat, WALL, sizeof mat);
	ttl = 0;
	for(int i=0;i<m;++i) {
		cin>>line;
		for(int j=0;j<n;++j) {
			char car = line[j];
			if(car=='#') {
				mat[i+1][j+1] = WALL;
			} else {
				mat[i+1][j+1] = EMPTY;
				x = i+1;
				y = j+1;
				++ttl;
			}
		}
	}

	ttl-= k;
	dfs(x,y);
	print(m,n);
	return 0;
}