#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_N 5001
using namespace std;

void capture(int arr[MAX_N], int& n) {
    cin>>n;
    for(int i=0;i<n;++i) cin>>arr[i];
}

void quicksort(int arr[MAX_N], int p,int q,int n) {
    if(p>=q) return;
    int j = p;
    for(int i=p;i<q;++i) {
        if(arr[i] < arr[q]) {
            swap(arr[i], arr[j]);
            ++j;
        }
    }
    
    swap(arr[j], arr[q]);
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    quicksort(arr, p, j-1, n);
    quicksort(arr, j+1, q, n);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int arr[MAX_N];
    int n;
    capture(arr, n);
    quicksort(arr, 0, n-1,n);
    return 0;
}

