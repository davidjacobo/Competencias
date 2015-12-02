#include <iostream>
#define MAX_N 100001

using namespace std;

void capture(int (&arr)[MAX_N], int& n,int& k) {
	cin>>n>>k;
	for(int i=0;i<n;++i) cin>>arr[i];
}

int solve(int b[MAX_N],int n,int k) {
	int temp[k];
	fill(temp, temp+k, 0);
	int i, j;
	for(i=n-1, j=k-1;i>=0 && j>=0;--i,--j) 
		temp[j] = b[i];

	for(j=0;j<k && i>=0;++j,--i) {
		temp[j]+= b[i];
	}

	int ans = -1;
	for(i=0;i<k;++i) {
		ans = max(ans, temp[i]);
	}	
	return ans;
}

int main() {
	int bells[MAX_N];
	int n,k;
	capture(bells, n, k);
	cout<<solve(bells, n, k)<<endl;
	return 0;
}