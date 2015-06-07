#include <cstring>
#include <iostream>
#include <cstdio>
#define MOD 1000007
#define MAX_N 1002
using namespace std;

int mat[MAX_N+1][MAX_N+1];

void dp(){
	memset(mat, 0, sizeof mat);
	mat[0][0] = 1;
	for(int i=0;i<MAX_N;++i)
		mat[i][0] = mat[i][i] = 1;
	mat[0][MAX_N] = 1;
	mat[1][MAX_N] = 3;

	int sum;
	for(int i=2;i<MAX_N;++i){
		sum = 2;
		for(int j=1;j<i;++j){
			mat[i][j] = (mat[i-1][j] + mat[i-1][j-1]) % MOD;
			sum += mat[i][j];
		}
		mat[i][MAX_N] = (mat[i-1][MAX_N] + sum) % MOD;
	}
}

int main(){
	int m,n;
	char line[MAX_N];
	dp();
	while(1){
		sscanf(gets(line), "%d %d", &m,&n);
		if(-1==m && -1==n) break;
		int ans = mat[n][MAX_N];
		if(m>0)
			ans-= mat[m-1][MAX_N];
		ans = (ans + MOD) % MOD;
		printf("%d\n", ans);
	}	
	return 0;
}
