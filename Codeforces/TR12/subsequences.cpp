#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX_N 100002
#define MAX_K 12
using namespace std;
typedef unsigned long long ll;
ll dp[MAX_N][MAX_K], bt[MAX_N];
int arr[MAX_N];

void init(int n) {
	memset(dp, 0, sizeof dp);
	for(int i=0;i<n;++i) {
		dp[i][0] = 1;
	}
}

void set(int i,int n,ll sum) {
	while(i<=n) {
		bt[i]+= sum;
		i+= i & (-i);
	}
}

ll get(int i) {
	ll ans = 0;
	while(i>0) {
		ans+= bt[i];
		i-= i & (-i);
	}
	return ans;
}

ll rekt_stuff(int n,int k) {
	ll sum;
	for(int i=1;i<k;++i) {
		memset(bt, 0, sizeof bt);
		set(arr[i-1],n,dp[i-1][i-1]);

		for(int j=i;j<n;++j) {
			/*sum = 0;
			for(int k=0;k<j;++k)
				if(arr[k] < arr[j])
					sum+= dp[k][i-1];
			*/


			dp[j][i] = get(arr[j]-1);
			set(arr[j],n,dp[j][i-1]);
		}
	}

	sum = 0;
	for(int i=k-1;i<n;++i) {
		sum+= dp[i][k-1];
	}
	return sum;
}

int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	++k;
	init(n);
	for(int i=0;i<n;++i) {
		scanf("%d",&arr[i]);
	}

	cout<<rekt_stuff(n,k)<<endl;
	return 0;
}