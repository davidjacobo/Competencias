#include <iostream>
#include <vector>

using namespace std;

void capture(vector<int>& arr) {
	int n,t;
	cin>>n;
	while(n--) {
		cin>>t;
		arr.push_back(t);
	}
}

void quick_median(vector<int>& arr,int p,int q) {
	int j = p;
	for(int i=p;i<q;++i) {
		if(arr[i] < arr[q]) {
			swap(arr[i], arr[j]);
			++j;
		}
	}

	swap(arr[j], arr[q]);
	if(j==arr.size()/2) {
		return;
	} else if(j > arr.size()/2) {
		quick_median(arr, p, j-1);
	} else {
		quick_median(arr, j+1, q);
	}
}

int main() {
	vector<int> arr;
	capture(arr);
	quick_median(arr, 0, arr.size()-1);
	cout<<arr[arr.size()/2]<<endl;
}