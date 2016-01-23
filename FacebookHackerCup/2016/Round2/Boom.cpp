#include <iostream>
#define MAX_N 100002

using namespace std;
string S,T;
bool flip[MAX_N];
int diffL[MAX_N], diffR[MAX_N];

void calc_diff(int n) {
	diffL[1] = diffR[n] = 1;

	for(int i=2;i<=n;++i) {
		diffL[i] = diffL[i-1];
		if(T[i-1]!=T[i-2]) ++diffL[i];
		//cout<<" "<<diffL[i];
	} 
	//cout<<endl;

	for(int i=n-1;i>=1;--i) {
		diffR[i] = diffR[i+1];
		if(T[i-1]!=T[i]) ++diffR[i];
		//cout<<" "<<diffR[i];
	}
	//cout<<endl;

	flip[0] = false;
	for(int i=1;i<=n;++i) {
		if(S[i-1]==T[i-1]) {
			flip[i] = false;
		} else {
			flip[i] = true;
		}
	}
}

int solve(int n) {
	int last_steps = 0, ans = (1<<30);

	for(int i=n;i>=1;--i) {
		if(flip[i]) {
			ans = min(ans, max(diffL[i], last_steps));
			last_steps = diffR[i];
		}
	}

	if(last_steps!=0)
		ans = min(ans, last_steps);

	if(ans == (1<<30)) ans = 0;
	return ans;
}

int main() {
	int t,n, counter = 1;
	cin>>t;
	while(t--) {
		cin>>n;
		cin>>S>>T;
		calc_diff(n);

		cout<<"Case #"<<counter++<<": "<<solve(n)<<endl;
	}
	return 0;
}