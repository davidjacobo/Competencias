#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 100001
#define INF 0x7FFFFFFF
using namespace std;
int arr[MAX_N];

void capture(int& n,int& k) {
    cin>>n>>k;
    for(int i=0;i<n;++i) cin>>arr[i];
    sort(arr, arr+n);
}

int delta(int n,int k) {
    int ans = INF;
    for(int i=k-1;i<n;++i) {
        ans = min(ans, arr[i]-arr[i-k+1]);
    }
    return ans;
} 

int main() {
    int n,k;
    capture(n,k);
    cout<<delta(n,k)<<endl;
    return 0;
}
