#include <iostream>
#define MAX_N 11
using namespace std;
typedef long long ll;
ll X[MAX_N], Y[MAX_N];

ll cmp_arr(int m,int bx,int n,int by) {
	ll x= 0, y=0;
	ll carry = 1;
	for(int i=0;i<m;++i) {
		x*= bx;
		x+= X[i];
		carry*= bx;
	}

	carry = 1;
	for(int i=0;i<n;++i) {
		y*= by;
		y+= Y[i];
		carry*= by;
	}
	// cout<<x<<endl<<y<<endl;

	return x-y;
}
int main() {
	int m,n,bx,by;
	ll x,y;
	cin>>m>>bx;
	for(int i=0;i<m;++i) {
		cin>>X[i];
	}

	cin>>n>>by;
	for(int i=0;i<n;++i) {
		cin>>Y[i];
	}

	ll cmp = cmp_arr(m,bx,n,by);
	if(cmp==0) {
		cout<<"=";
	} else if(cmp>0) {
		cout<<">";
	} else {
		cout<<"<";
	}
	return 0;
}