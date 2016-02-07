#include <iostream>
#include <cstring>
#define MAX_N 100001
using namespace std;
bool used[MAX_N];

void capture(int& n) {
	memset(used, false, sizeof used);
	cin>>n;
	int t;
	for(int i=0;i<n;++i) {
		cin>>t;
		used[t] |= true;
	}
}

void print_sol(int n) {
	for(int i=1;i<=n;++i) {
		if(!used[i]) cout<<i<<" ";
	}
	cout<<endl;
}

int main() {
	int n;
	capture(n);
	print_sol(n);
	return 0;
}