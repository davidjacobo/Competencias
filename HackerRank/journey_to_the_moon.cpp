#include <iostream>
#include <vector>
#define MAX_N 100001

using namespace std;
typedef long long ll;
int cmp[MAX_N], siz[MAX_N];

void init_cmp(int n) {
	for(int i=0;i<n;++i) {
		cmp[i] = i;
		siz[i] = 1;
	}
}

int find(int x) {
	if(x==cmp[x]) return x;
	return cmp[x] = find(cmp[x]);
}

ll capture() {
	int x,y,cmp_x,cmp_y,n,l;
	cin>>n>>l;
	init_cmp(n);

	while(l--) {
		cin>>x>>y;
		cmp_x = find(x);
		cmp_y = find(y);
		if(cmp_x!=cmp_y) {
			if(cmp_x < cmp_y)	swap(cmp_x, cmp_y);
 			cmp[cmp_x] = cmp_y;
			siz[cmp_y] += siz[cmp_x];
		}
	}

	vector<int> out;
	bool used[MAX_N];
	fill(used, used+MAX_N, 0);
	ll sum = 0;
	for(int i=0;i<n;++i) {
		cmp_x = find(i);

		if(!used[cmp_x]) {
			used[i] = used[cmp_x] = true;
			out.push_back(siz[cmp_x]);
			sum+= siz[cmp_x];
		}
	}

	ll ans = 0;
	for(vector<int>::iterator it = out.begin();it!=out.end();++it) {
		ans += (sum-(*it))*(*it);
	}

	return ans>>1;
}

int main() {
	int n,l;
	cout<<capture()<<endl;
	return 0;
}