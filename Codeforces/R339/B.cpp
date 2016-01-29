#include <iostream>

using namespace std;

bool only_one(string input) {
	if(input.size()==1 && input[0]=='0') return true;

	if(input[0]!='1')	return false;
	for(int i=1;i<input.size();++i) {
		if(input[i]!='0') return false;
	}
	return true;
}

void capture() {
	int zeros = 0, n;
	string no_zeros_only = "";
	string input;
	bool fucked = false;
	cin>>n;

	while(n-- && !fucked) {
		cin>>input;

		if(only_one(input)) {
			zeros+= input.size()-1;
			if(input[0]=='0') {
				fucked = true;
			}
		} else {
			no_zeros_only = input;
		}
	}

	if(fucked) {
		cout<<0<<endl;
	} else {
		if(no_zeros_only.size()==0) cout<<1;
		cout<<no_zeros_only;
		while(zeros--) 
			cout<<0;
		cout<<endl;
	}
}

int main() {
	int n;
	capture();
	return 0;
}