#include <iostream>
#include <vector>
#define INF (1<<30)

using namespace std;
vector<int> nums;

void evaluate(int& sum,int& minp,int& maxp,int n,int num) {
	sum = 0;
	minp = INF;
	maxp = -INF;
	for(int i=0;i<n;++i) {
		if(num&(1<<i)) {
			sum+= nums[i];
			minp = min(minp, nums[i]);
			maxp = max(maxp, nums[i]);
		}
	}
}

int solve(int n,int l,int r,int x) {
	int sum,minp,maxp;
	int ans = 0;
	for(int i=1;i<(1<<n);++i) {
		evaluate(sum, minp, maxp, n, i);
		if(maxp-minp >= x && sum>= l && sum<= r) ++ans;
	}
	return ans;
}

int main() {
	int n,l,r,x;
	cin>>n>>l>>r>>x;
	for(int i=0;i<n;++i) {
		int t;
		cin>>t;
		nums.push_back(t);
	}

	cout<<solve(n,l,r,x)<<endl;
}