#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_N 101
using namespace std;

int capture(vector<int>& arr1) {
    int m,min_val = (1<<30),t;
    cin>>m;
    while(m--) {
        cin>>t;
        arr1.push_back(t);
        min_val = min(min_val, t);
    }
    return min_val;
}

void solve(const vector<int>& arr1,const vector<int>& arr2,int min_val) {
    int counter[MAX_N];
    fill(counter, counter+MAX_N, 0);
    
    for(auto x:arr1) --counter[x-min_val];
    for(auto x:arr2) ++counter[x-min_val];
    
    for(int i=0;i<MAX_N;++i) {
        if(counter[i] > 0)
            cout<<(i+min_val)<<" ";
    }
    cout<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> arr1,arr2;
    capture(arr1);
    int min_val = capture(arr2);
    solve(arr1,arr2,min_val);
    return 0;
}
