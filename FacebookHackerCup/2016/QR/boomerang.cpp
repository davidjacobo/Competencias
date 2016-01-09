#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vii points;

void capture() {
	int n,x,y;
	points.clear();
	cin>>n;
	while(n--) {
		cin>>x>>y;
		points.push_back(ii(x,y));
	}
}

int solve() {
	unordered_map<int, int> umap;
	int n = points.size();
	int ans = 0;

	for(int i=0;i<n;++i) {
		umap.clear();

		for(int j=0;j<n;++j) {
			int a = (points[i].first-points[j].first);
			int b = (points[i].second-points[j].second);
			int dist = a*a + b*b;

			if(umap.count(dist) > 0) {
				umap[dist]++;
			} else {
				umap[dist] = 1;
			}
		}

		for(auto x:umap) {
			if(x.second > 1) {
				ans+= ((x.second)*(x.second-1))>>1;
			}
		}
	}

	return ans;
}

int main() {
	int t, counter = 1;
	cin>>t;
	while(t--) {
		capture();
		cout<<"Case #"<<counter++<<": "<<solve()<<endl;
	}
	return 0;
}