#include <iostream>
#include <cmath>

using namespace std;

void print_mat(const string& cad,int m,int n) {
	int k, len = cad.size();
	for(int i=0;i<n;++i) {
		k = i;
		for(int j=0;j<m;++j) {
			if(k>=len) break;
			cout<<cad[k];
			k+= n;
		}

		cout<<" ";
	}
	cout<<endl;
}

int main() {
	string input;
	cin>>input;
	int len = input.size();
	int m = floor(sqrt(len));
	int n = ceil(sqrt(len));
	if(m*n < len) ++m;
	print_mat(input,m,n);
	return 0;
}