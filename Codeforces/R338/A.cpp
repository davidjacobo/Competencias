#include <iostream>
#include <cstring>
#define MAX_N 101

using namespace std;

int main() {
	bool used[MAX_N];
	memset(used, false, sizeof used);
	int m,n,t,o;
	cin>>m>>n;
	for(int i=0;i<m;++i) {
		cin>>o;
		for(int j=0;j<o;++j) {
			cin>>t;
			used[t] = true;
		}
	}

	bool win = true;
	for(int i=1;i<=n;++i) {
		if(!used[i]) win = false;
	}

	cout<<((win)?"YES":"NO")<<endl;
	return 0;
}