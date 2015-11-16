#include <iostream>
#define MAX_M 31
#define MAX_N 31
#define MAX_CUT 901
#define INF 0x0FFFFFFFFFFFFFFF
#define INV -1
using namespace std;
typedef long long ll;

ll dp[MAX_M][MAX_N][MAX_CUT];

int rekt_shit(int row,int col,int cut) {
	if(INV!=dp[row][col][cut]) return dp[row][col][cut];

	ll ans = INF, cut_cost;
	int area0,area1;
	//Do your magic pls!
	for(int i=1;i<row;++i) {
		area0 = i*col;
		area1 = (row-i)*col;
		cut_cost = col*col;
		//try to fit all up
		if(area0 >= cut) {
			cut_cost += rekt_shit(i, col, cut);
		} else {
			cut_cost += rekt_shit(row-i, col, cut-area0);
		}

		ans = min(ans, cut_cost);
	}

	for(int j=1;j<col;++j) {
		area0 = j*row;
		area1 = (col-j)*row;
		cut_cost = row*row;

		if(area0 >= cut) {
			cut_cost += rekt_shit(row, j, cut);
		} else {
			cut_cost += rekt_shit(row, col-j, cut-area0);
		}

		ans = min(ans, cut_cost);
	}
	return dp[row][col][cut] = ans;
}

ll solve(int r,int c,int k) {
	return (dp[r][c][k]!=INV)?dp[r][c][k]:rekt_shit(r,c,k); 
}

void init() {
	for(int i=0;i<MAX_M;++i) {
		for(int j=0;j<MAX_N;++j) {
			for(int k=0;k<MAX_CUT;++k) {
				if(i*j==k) {
					dp[i][j][k] = 0;
				} else {
					dp[i][j][k] = INV;
				}
			}
		}
	}
}

int main() {
	init();
	int t,r,c,k;
	cin>>t;
	while(t--) {
		cin>>r>>c>>k;
		cout<<solve(r,c,k)<<endl;
	}
	return 0;
} 