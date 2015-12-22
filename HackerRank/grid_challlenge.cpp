#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 101

using namespace std;
typedef vector<int> vi;
vector<vi> mat;

void capture_sort(int& n) {
	string input;
	mat.clear();
	vector<int> arr;
	cin>>n;
	for(int i=0;i<n;++i) {
		cin>>input;
		arr.clear();
		for(int j=0;j<n;++j) {
			arr.push_back(input[j]);
		}
		sort(arr.begin(), arr.end());
		mat.push_back(arr);
	}
}

bool is_sorted(int n) {
	for(int i=0;i<n;++i) {
		for(int j=0;j<n;++j) {
			if(i>0)	if(mat[i][j] < mat[i-1][j]) return false;
			if(j>0) if(mat[i][j] < mat[i][j-1]) return false;
		}
	}	
	return true;
}

int main() {
	int t, n;
	cin>>t;
	while(t--) {
		capture_sort(n);
		cout<<((is_sorted(n))?"YES":"NO")<<endl;
	}
	return 0;
}