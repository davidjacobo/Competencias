#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int capture(vector<int>& arr) {
    int n, ans = 0, t;
    cin>>n;
    arr.clear();
    for(int i=0;i<n;++i) {
        cin>>t;
        ans+= t;
        arr.push_back(t);
    }
    return ans;
}

void solve(vector<int> arr,int sum) {
    int so_far =0;
    for(int i=0;i<arr.size();++i) {
        if((sum-arr[i])/2 == so_far) {
            cout<<"YES"<<endl;
            return;
        }
        
        so_far += arr[i];
    }
    
    cout<<"NO"<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> arr;
    int t,sum;
    cin>>t;
    while(t--) {
        sum = capture(arr);
        solve(arr, sum);
    }
    return 0;
}
