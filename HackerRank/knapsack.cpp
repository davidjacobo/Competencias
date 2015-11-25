#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX_N 2001
using namespace std;
bool used[MAX_N];
int arr[MAX_N];

int knap(int n,int k) {
    used[0] = true;
    sort(arr, arr+n);
    for(int i=0;i<n;++i) {
        int val = arr[i];
        for(int j=val;j<=k;++j) {
            if(used[j-val]) used[j] = true;
        }
    }
    
    for(int i=k;i>=0;--i) {
        if(used[i]) return i;
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=0;i<n;++i) cin>>arr[i];
        memset(used, false, sizeof used);
        cout<<knap(n,k)<<endl;
    }
    return 0;
}
