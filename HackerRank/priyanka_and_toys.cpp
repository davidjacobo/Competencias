#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr;

void capture() {
	int n, t;
	cin>>n;
	while(n--) {
		cin>>t;
		arr.push_back(t);
	}

	sort(arr.begin(), arr.end());
}

int solve() {
	int n = arr.size(), tope, ans = 1;
	tope = arr[0] + 4;

	for(int i=1;i<n;++i) {
		if(arr[i] > tope) {
			tope = arr[i]+4;
			++ans;
		}
	}
	return ans;
}

int main() {
	capture();
	cout<<solve()<<endl;
	return 0;
}