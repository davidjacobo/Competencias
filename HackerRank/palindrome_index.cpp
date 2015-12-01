#include <iostream>

using namespace std;

bool is_palindrome(const string& input) {
    int len = input.size();
    
    for(int i=0;i<(len>>1);++i) {
        if(input[i]!=input[len-i-1]) return false;
    }
    return true;
}

int solve(const string& input) {
	int len = input.size();
	for(int i=0;i<=(len>>1);++i) 
		if(input[i]!=input[len-1-i]) {
			//answer must be i or len-1-i
            if(is_palindrome(input.substr(i, len-i-i-1)))
                return len-1-i;
            else
                return i;
		}
	return -1;
}

int main() {
	int t;
	string input;
	cin>>t;
	while(t--) {
		cin>>input;
		cout<<solve(input)<<endl;
	}
	return 0;
}