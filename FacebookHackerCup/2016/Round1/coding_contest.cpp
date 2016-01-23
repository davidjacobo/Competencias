#include <iostream>
#include <vector>
#include <cstring>
#define MAX_N 100001

using namespace std;
typedef vector<int> vi;
vi nums;

void capture() {
	nums.clear();
	int n,d;
	cin>>n;
	while(n--) {
		cin>>d;
		nums.push_back(d);
	}
}

int solve() {
	int ans = 0;
	bool used[MAX_N];
	memset(used, false, sizeof used);
	for(int i=0;i<nums.size();++i) {
		if(used[i]) {
			continue;
		} else {
			used[i] = true;
			//Ideally, let's mark the next 3 cells
			int upper = nums[i]+10;
			int lower = nums[i];
			int j = i+1;
			int k = 0;
			while(k++<3) {
				if(j<nums.size()) {
					if(nums[j] <= upper && nums[j] > lower) {
						lower = nums[j];
						upper = nums[j]+10;
						used[j] = true;
						++j;
					} else {
						lower = upper;
						upper+= 10;
						++ans;
					}
				} else {
					lower = upper;
					upper+= 10;
					++ans;
				}
			}
		}
	}

	return ans;
}

int main() {
	int t,n, counter = 1;
	cin>>t;
	while(t--) {
		capture();
		cout<<"Case #"<<counter++<<": "<<solve()<<endl;
	}
	return 0;
}