#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

typedef pair<int,string> is;
typedef vector<is> vis;
vis arr[MAX_N];

int capture() {
    int n, t;
    string input;
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>t>>input;
        arr[t].push_back(is(i, input));
    }
    
    return n;
}

void solve(int n) {
    int mid = (n>>1);
    for(int i=0;i<MAX_N;++i) {
        for(int j=0;j<arr[i].size();++j) {
            is temp = arr[i][j];
            if(temp.first < mid) {
                cout<<"-"<<" ";
            } else {
                cout<<temp.second<<" ";
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = capture();
    solve(n);
    return 0;
}
