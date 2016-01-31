#include <iostream>

using namespace std;

int look_for(string input, int k,int index) {
	for(int i=0;i<25;++i) {
		int target = (i*4 + k)*10 + (input[index] - '0');

		for(int p=0;p<index;++p) {
			for(int q=p+1;q<index;++q) {
				int num = (input[p]-'0')*100 + (input[q]-'0')*10 + (input[index]-'0');

				if(num==target) {
					return target;
				}
			}
		}
	}

	return -1;
}

int solve(string input) {
	for(int i=1;i<input.size();++i) {
		if(input[i]=='0' || input[i]=='8') {
			cout<<"YES"<<endl;
			return input[i]-'0';
		}
	}

	int out = -1;
	for(int i=input.size()-1;i>0;--i) {
		if(input[i]=='6') {
			out = look_for(input,1,i);
		} else if(input[i]=='4') {
			out = look_for(input,2,i);
		} else if(input[i] == '2') {
			out = look_for(input,3,i);
		}

		if(out > -1) {
			cout<<"YES"<<endl;
			return out;
		}
	}

	return -1;
}

int main() {
	string s;
	cin>>s;
	s = "0"+s;
	int out = solve(s);
	if(out==-1) {
		cout<<"NO"<<endl;
	} else {
		cout<<out<<endl;
	}
	return 0;
}