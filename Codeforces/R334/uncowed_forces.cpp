#include <iostream>
#include <cmath>
#define MAX_N 5

using namespace std;

void capture(int (&arr)[MAX_N]) {
	for(int i=0;i<MAX_N;++i) cin>>arr[i];
}

int solve(const int ac[MAX_N],const int w[MAX_N]) {
	int x[] = {500,1000,1500,2000,2500};
	double ans = 0.0;
	for(int i=0;i<MAX_N;++i) {
		ans+= max(0.3*x[i] , (1.0-ac[i]/250.0)*x[i]-50*w[i]);
	}

	int h,f;
	cin>>h>>f;
	ans+= (h*100 - f*50);
	return max((int)ans, 0);
}

int main() {
	int w[MAX_N], ac[MAX_N];
	capture(ac);
	capture(w);
	cout<<solve(ac,w)<<endl;
	return 0;
}