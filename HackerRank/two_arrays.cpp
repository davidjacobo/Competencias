#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_N 1001
using namespace std;
int A[MAX_N], B[MAX_N];

bool can_sum(int n,int k) {
    for(int i=0;i<n;++i) {
        if(A[i]+B[n-i-1] < k) return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=0;i<n;++i) {
            cin>>A[i];
        }
        
        for(int i=0;i<n;++i) {
            cin>>B[i];
        }
        
        sort(A, A+n);
        sort(B, B+n);
        if(can_sum(n,k)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}