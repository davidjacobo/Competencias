#include <iostream>

using namespace std;
typedef long long ll;

bool inside(ll p,ll q,ll r) {
	return r<=q && r>=p;
}

int main() {
	ll INF = (1LL<<62);
	ll p, q, r, limit;
	cin>>p>>q>>r;
	limit = INF/r;
	
	int in_count = 0;
	ll base = 1;
	while(base <=q) {
		if(inside(p,q,base)) {
			++in_count;
			cout<<base<<" ";
		}

		if(base >= limit) break;
		base*= r;
	}

	if(in_count==0) cout<<-1;

	return 0;
} 