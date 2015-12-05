#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll a,b,m;
	int t;
	cin>>t;
	while(t--) {
		cin>>a>>b>>m;
		m = (m*(m+1))>>1;
		if(a < b) swap(a,b);

		if(m >= b) {
			cout<<a-b<<endl;
		} else {
			a-= m;
			b-= m;
			cout<<a+b<<endl;
		}
	}
	return 0;
}