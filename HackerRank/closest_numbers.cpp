#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_N 200001
using namespace std;
typedef pair<int,int> ii;

void capture(vector<int>& arr) {
    int n,t;
    cin>>n;
    while(n--) {
        cin>>t;
        arr.push_back(t);
    }
    
    sort(arr.begin(), arr.end());
}

void solve(const vector<int> arr) {
    vector<ii> output;
    int min_diff = (1<<30);
    for(int i=1;i<arr.size();++i) {
        int diff = arr[i]-arr[i-1];
        if(diff < min_diff) {
            min_diff = diff;
            output.clear();
            output.push_back(ii(arr[i-1], arr[i]));
        } else if(diff == min_diff) {
            output.push_back(ii(arr[i-1], arr[i]));
        }
    }
    
    for(auto temp:output) {
        cout<<temp.first<<" "<<temp.second<<" ";
    }
    cout<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    vector<int> arr;
    capture(arr);
    solve(arr);
    return 0;
}
