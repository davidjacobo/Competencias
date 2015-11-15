#include <iostream>
#define MAX_N 50001
using namespace std;
typedef long long ll;

void capture_input(int *p,int& n){
	cin>>n;
	for(int i=0;i<n;++i) cin>>p[i];
}

ll solve(int *p,int n) {
	ll ans = 0;
	int max_val = p[n-1];
	for(int i=n-2;i>=0;--i) {
		if(p[i] > max_val) {
			max_val = p[i];
			continue;
		}

		if(p[i] < max_val) {
			//if I can get profit, I maximize it
			ans+= (max_val - p[i]);
		}
	}
	return ans;
}

int main() {
	int n, A[MAX_N],t;
	cin>>t;
	while(t--) {
		capture_input(A,n);
		cout<<solve(A,n)<<endl;
	}
	return 0;
}