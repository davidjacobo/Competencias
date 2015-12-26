#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_N 100001
using namespace std;
int arr[MAX_N], ind[MAX_N];

int main() {
    int n,k,t;
    cin>>n>>k;
    for(int i=0;i<n;++i) {
        cin>>t;
        --t;
        arr[i] = t;
        ind[t] = i;
    }
    
    for(int i=0;i<n && k>0;++i) {
        if(arr[i]!=n-i-1) {
            ind[arr[i]] = ind[n-i-1];
            //cout<<"swap all this sheit"<<endl;
            --k;
            t = arr[i];
            arr[i] = n-i-1;
            arr[ind[n-i-1]] = t;
        }
    }
    
    for(int i=0;i<n;++i) {
        cout<<arr[i]+1<<" ";
    }
    return 0;
}
