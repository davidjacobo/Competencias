#include <iostream>

using namespace std;

int count_this(string in, string pat) {
	int ans = 0,ind = -1;
	while((ind = in.find(pat, ind+1))!= string::npos) {
		++ans;
	}
	return ans;
}

void solve(string s) {
	int as,bs;
	as = count_this(s, "BA");
	bs = count_this(s, "AB");

	int i = s.find("BA");
	int j = s.find("AB");

	if(as==0 || bs==0) {
		cout<<"NO";
		return;
	}

	if(as==1) {
		int index = -1;
		while((index = s.find("AB", index+1)) != string::npos) {
			if(abs(index-i) > 1) {
				cout<<"YES";
				return;
			}
		}
	} else if(bs==1) {
		int index = -1;
		while((index = s.find("BA", index+1)) != string::npos) {
			if(abs(index-j) > 1) {
				cout<<"YES";
				return;
			}
		}
	} else {
		//2 or more of each, easy case
		cout<<"YES";
		return;
	}

	cout<<"NO";
}

int main() {
	string s;
	cin>>s;
	solve(s);
	return 0;
}