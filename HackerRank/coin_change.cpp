#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 251
#define MAX_C 51
using namespace std;
typedef long long ll;
ll ways[MAX_N];

void capture_input(int c,int (&coins)[MAX_C]) {
	for(int i=0;i<c;++i) cin>>coins[i];

	sort(coins, coins+c);
}

void solve(int n,int c,int (&coins)[MAX_C]) {
	memset(ways, 0, sizeof ways);
	ways[0] = 1;

	for(int i=0;i<c;++i) {
		int coin = coins[i];
		for(int j=coin;j<=n;++j) {
			ways[j]+= ways[j-coin];
		}
	}
}

int main() {
	int n,c;
	int coins[MAX_C];
	cin>>n>>c;
	capture_input(c,coins);
	solve(n,c,coins);

	cout<<ways[n]<<endl;
 	return 0;
}