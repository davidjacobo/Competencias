#include <iostream>
#include <stack>

using namespace std;

void solve(int n) {
	stack<int> s;
	if(n==1) {
		cout<<1<<endl;
		return;
	} else {
		int t;
		s.push(1);
		--n;

		while(n--) {
			int num = 1;

			while(!s.empty()) {
				t = s.top();
				if(t==num) {
					s.pop();
					++num;
				} else {
					s.push(num);
					break;
				}
			}

			if(s.empty())
			s.push(num);
		}
	}

	stack<int> out;
	while(!s.empty()) {
		int t = s.top();
		s.pop();

		out.push(t);
	}

	while(!out.empty()) {
		int t = out.top();
		out.pop();
		cout<<t<<" ";
	}
	cout<<endl;
}

int main() {
	int n;
	cin>>n;
	solve(n);
	return 0;
}