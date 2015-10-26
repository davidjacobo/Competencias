#include <iostream>
#include <cstring>
#include <vector>
#define MAX_N 500001
#define MAX_IT 1300
 
using namespace std;
vector<int> q, back;
bool A[MAX_N], fixedd[MAX_N];

void detect_blocks(int n) {
	for(int i=1;i<n-1;++i){
		if(A[i]==A[i-1] || A[i]==A[i+1]) {
			fixedd[i] = true;
			back.push_back(i);
		}
	}
}

int flood(int n) {
	int t, ind, tim = 0;
	do{
		q = back;
		back.clear();

		bool moved = false;
		for(int i=0;i<q.size();++i) {
			ind = q[i];
			t = ind-1;
			if(t > 0 && !fixedd[t]) {
				fixedd[t] = true;
				A[t] = A[ind];
				back.push_back(t);
				moved = true;
			}

			t = ind+1;
			if(t < n-1 && !fixedd[t]) {
				fixedd[t] = true;
				A[t] = A[ind];
				moved = true;
				back.push_back(t);
			}
		}
		if(moved) ++tim;
	}while(back.size() > 0);

	return tim;
}

int main() {
	int n,t;
	cin>>n;

	memset(fixedd, false, sizeof fixedd);
	for(int i=0;i<n;++i){
		cin>>t;
		if(t==1) A[i] = true;
		else A[i] = false;
	}

	fixedd[0] = fixedd[n-1] = true;
	back.push_back(0);
	back.push_back(n-1);

	detect_blocks(n);
	cout<<flood(n)<<endl;
	for(int i=0;i<n;++i) {
		if(A[i]) cout<<"1 ";
		else cout<<"0 "; 
	}
	cout<<endl;

	return 0;
}