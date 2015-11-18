#include <iostream>

using namespace std;

int main() {
	int n,rounds,ans = 0, budget, sum,daedalus,t;
	cin>>n>>rounds;
	for(int i=0;i<rounds;++i) {
		cin>>budget>>daedalus;
		sum = daedalus;
		for(int j=1;j<n;++j) {
			cin>>t;
			sum+= t;
		}

		int new_val;

		if(sum>budget) {
			sum-= daedalus;
			daedalus = 0;
			new_val = 1;
			++sum;
		} else {
			new_val = daedalus;
		}

		while(sum<=budget) {
			new_val*= 10;
			sum+= (new_val-new_val/10);
		}

		new_val/= 10;
		if(new_val > daedalus) {
			ans+= new_val-daedalus;
		}
	}

	cout<<ans<<endl;
}