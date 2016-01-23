#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define MOD 1000000007
#define INF (1<<30)

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vii input;

void capture(int n) {
	int x,h;
	input.clear();
	for(int i=0;i<n;++i) {
		cin>>x>>h;
		input.push_back(ii(h,x));
	}

	sort(input.begin(), input.end());
}

ll solve() {
	set<int> s;
	vi buffer;
	ll ans  = 0;
	int last_h = -1;
	s.insert(INF);
	s.insert(-INF);

	for(int i=input.size()-1; i>0;--i) {
		ii t_pivot = input[i];
		int hp = t_pivot.first;
		int xp = t_pivot.second;
		//cout<<"processing: "<<xp<<" : "<<hp<<endl;

		if(hp != last_h) {
			//put buffer into set
			for(int k=0;k<buffer.size();++k) 
				s.insert(buffer[k]);
			buffer.clear();
		} 

		auto low_p = s.lower_bound(xp);
		--low_p;
		int low = *(low_p);
		int up = *(s.upper_bound(xp));
		//cout<<"bounds: "<<low<<" : "<<up<<endl;

		//alright then (low, up ) is a range that I cannot touch

		for(int j=i-1;j>=0;--j) {
			ii t_this = input[j];
			int ht = t_this.first;
			int xt = t_this.second;

			if(xt <= low || xt >= up || hp!=ht) break;

			ans = (ans + (ll)(xp-xt)*(xp-xt)) % MOD;
		}

		last_h = hp;
		buffer.push_back(xp);
	}
	return ans;
}

int main() {
	int t,n,counter = 1;
	cin>>t;
	while(t--) {
		cin>>n;
		capture(n);
		cout<<"Case #"<<counter++<<": "<<solve()<<endl;
	}
	return 0;
}