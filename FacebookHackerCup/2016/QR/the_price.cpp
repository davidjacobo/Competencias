#include <iostream>
#define MAX_N 100001

using namespace std;
int arr[MAX_N];

int main() {
	int t,n,p,counter = 1;
	cin>>t;
	while(t--) {
		cin>>n>>p;
		for(int i=0;i<n;++i) 
			cin>>arr[i];

		int i=0, j=0, sum=0, ans=0;
		while(i<n) {
			if(arr[i] > p) {
				sum = 0;
				j = ++i;
				continue;
			}

			while(j<n && sum+arr[j]<=p) {
				sum+= arr[j++];
			}

			ans+= (j-i);
			sum-= arr[i++];
		}

		cout<<"Case #"<<counter++<<": "<<ans<<endl;
	}
	return 0;
}