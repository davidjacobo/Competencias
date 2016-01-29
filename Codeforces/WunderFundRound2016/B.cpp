#include <iostream>
#include <cstring>
#define MAX_N 51

using namespace std;
int counter[MAX_N][MAX_N];

void capture(int& n) {
	cin>>n;
	int t;
	memset(counter, 0, sizeof counter);
	for(int i=0;i<n;++i) {
		for(int j=0;j<n;++j) {
			cin>>t;
			if(t!=0) {
				counter[j][t]++; 
			}
		}
	}
}

void solve(int n) {
	bool used[MAX_N];
	int out[MAX_N];
	memset(used, false, sizeof used);
	int look = n-1;
	for(int i=1;i<=n;++i) {
		for(int j=0;j<n;++j) {
			if(used[j]) continue;

			if(counter[j][i]==look) {
				out[j] = i;
				used[j] = true;
				if(look!=1)
					--look;
				break;
			}
		}
	}

	for(int i=0;i<n;++i) {
		if(!used[i]) {
			cout<<n<<" ";
		} else {
			cout<<out[i]<<" ";
		} 
	}
	cout<<endl;
}

int main() {
	int n;
	capture(n);
	solve(n);
	return 0;
}