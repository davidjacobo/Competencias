#include <iostream>
#include <queue>
#define MAX_N 100003

using namespace std;
typedef pair<int,int> ii;

void capture_input(int (&arr)[MAX_N],int& n,priority_queue<ii>& pq) {
	int t;
	cin>>n;
	arr[0] = arr[n+1] = 0;
	for(int i=0;i<n;++i) {
		cin>>t;
		pq.push(ii(-t,i+1));
		arr[i+1] = t;
	}
}

int solve(int (&arr)[MAX_N], int n, priority_queue<ii> pq) {
	ii temp;
	int ans = 0;
	int ind, add;
	int welp[MAX_N];
	welp[0] = welp[n+1] = 0;

	while(!pq.empty()) {
		ii temp = pq.top();
		ind = temp.second;
		pq.pop();

		if(arr[ind] > arr[ind-1] && arr[ind] > arr[ind+1]) {
			add = max(welp[ind-1], welp[ind+1]) + 1;
		} else if(arr[ind] > arr[ind-1]) {
			add = welp[ind-1]+1;
		} else if(arr[ind] > arr[ind+1]) {
			add = welp[ind+1]+1;
		} else {
			//Either you are the min of the triplet OR they are
			//all the same
			add = 1;
		}

		welp[ind] = add;
		ans+= add;
	}
	return ans;
}

int main() {
	priority_queue<ii> pq;
	int n, A[MAX_N];
	capture_input(A,n,pq);
	cout<<solve(A,n,pq)<<endl;
	return 0;
}