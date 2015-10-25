#include <iostream>
#include <cstring>
#define MAX_N 100001

using namespace std;
char a[MAX_N], b[MAX_N], c[MAX_N];

int diff(int n,int t) {
	bool used[MAX_N];
	memset(used, false, sizeof used);
	int ans = 0;
	for(int i=0;i<n;++i) {
		if(a[i]==b[i] && t>0) {
			++ans;
			c[i] = a[i];
			used[i] = true;
			--t;
		} else {
			c[i] = 'a';
			if(c[i]==a[i] || c[i]==b[i]) {
				c[i] = 'b';
			} 

			if(c[i]==a[i] || c[i]==b[i]) {
				c[i] = 'c';
			}
		}
	}

	int t1 = t, t2 = t;

	for(int i=0;i<n;++i){
		if(a[i]!=b[i] && t1>0) {
			c[i] = a[i];
			--t1;
			used[i] = true;
		}
	}

	for(int i=0;i<n;++i) {
		if(a[i]!=b[i] && !used[i] && t2>0) {
			c[i] = b[i];
			--t2;
		}
	}

	c[n] = '\0';
	return (t1+t2>0)?-1:0;
}

int main() {
	int n,t;
	cin>>n>>t;
	cin>>a>>b;

	if(diff(n,n-t)!=-1) {
		cout<<c;
	} else {
		cout<<-1;
	}
	return 0;
}