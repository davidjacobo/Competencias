#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void capture(vector<int>& arr,set<int>& st,int& n,int& k) {
    int t;
    cin>>n>>k;
    for(int i=0;i<n;++i) {
        cin>>t;
        arr.push_back(t);
        st.insert(t);
    }
    
    sort(arr.begin(), arr.end());
}

int solve(const vector<int> arr,const set<int> st,int k) {
    int ans = 0;
    for(auto x:arr) {
        int other = x - k;
        if(st.find(other)!=st.end()) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    vector<int> arr;
    set<int> st;
    int n,k;
    capture(arr,st,n,k);
    cout<<solve(arr, st, k)<<endl;
}