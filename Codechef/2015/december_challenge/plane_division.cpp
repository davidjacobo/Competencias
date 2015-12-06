#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,long double> iii;
typedef vector<iii> viii;
viii points;

int solve() {
	iii pivot  = points[0];
	int counter = 1, max_counter = 1;
	for(int i=1;i<points.size();++i) {
		if(pivot.first.first!= points[i].first.first ||
			pivot.first.second!=points[i].first.second) {
			pivot = points[i];
			counter = 0;
		}

		++counter;
		max_counter = max(max_counter, counter);
	}

	return max_counter;
}

int pos(int a) {
	if(a<0) return -a;
	return a;
}

int gcd(int a,int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int calc_div(int a,int b,int c) {
	a = pos(a);
	b = pos(b);
	c = pos(c);

	a = gcd(max(a, b), min(a, b));
	return a;
}

void capture() {
	int n, a, b, c;
	points.clear();
	cin>>n;
	while(n--) {
		cin>>a>>b>>c;
		int div = calc_div(a,b,c);
		if(a < 0) div*= -1;

		//FIX HERE, dont use imprecise c/div
		//instead calc the gcd again and keep both terms to compare
		points.push_back(iii(ii(a/div, b/div), (long double)c/div));
	}

	sort(points.begin(), points.end());
	viii::iterator it = unique(points.begin(), points.end());
	points.resize(distance(points.begin(), it));
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		capture();
		cout<<solve()<<endl;
	}
	return 0;
}