#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin>>N;
	int nums[N+1];
	for(int i=0;i<N;i++)
		cin>>nums[i];
	nums[N] = 2000000000;
	sort(nums, nums+(N+1));

	int j;
	for(int i=0;i<N;i++) {
		if(nums[i]==nums[i+1]) {
			//repeated :'(
			j = i;
			i++;
			while(i<N && nums[i]==nums[j]) i++;
			i--;
		} else {
			j = nums[i];
			break;
		}
	}

	cout<<j<<endl;
	return 0;
}
