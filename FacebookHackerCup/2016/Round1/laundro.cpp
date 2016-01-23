#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ll_ll;

priority_queue<ll_ll> pq;
queue<ll> q;

void capture(int& l,int& n,int& m,int& d) {
	pq = priority_queue<ll_ll>();
	cin>>l>>n>>m>>d;
	ll t;
	for(int i=0;i<n;++i) {
		cin>>t;
		pq.push(ll_ll(-t, t));
	}

	q = queue<ll>();
	for(int i=0;i<min(l,m);++i) {
		q.push(0);
	}
}

ll solve(int l,int n,int m,int d) {
	ll laundry_output = 0;

	while(l-->0) {
		ll_ll temp = pq.top();
		pq.pop();

		ll finish = -temp.first;
		ll charge = temp.second;

		pq.push(ll_ll(-(finish+charge), charge));

		ll drier = q.front();
		q.pop();
		ll insert_charge = max(drier , finish);
		laundry_output = insert_charge + d;
		q.push(laundry_output);
	}

	return laundry_output;
}

int main() {
	int t,l,m,n,d,counter = 1;
	cin>>t;
	while(t--) {
		capture(l,n,m,d);
		cout<<"Case #"<<counter++<<": "<<solve(l,n,m,d)<<endl;
	}
	return 0;
}