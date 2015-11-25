#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 101
#define INV -1
#define DOWN 2
#define LEFT 3
using namespace std;
int arrA[MAX_N], arrB[MAX_N], dp[MAX_N][MAX_N],parent[MAX_N][MAX_N];

void lcs(int m,int n) {
    memset(dp, 0, sizeof dp);
    memset(parent, INV, sizeof parent);
    for(int i=1;i<=m;++i) {
        for(int j=1;j<=n;++j) {
            if(arrA[i]==arrB[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                parent[i][j] = 0;
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(dp[i-1][j] > dp[i][j-1])
                    parent[i][j] = DOWN;
                else
                    parent[i][j] = LEFT;
            }
        }
    }
    
    vector<int> output;
    int i = m, j = n;
    while(j>0 && i>0) {
        if(parent[i][j]==0) {
            output.push_back(arrB[j]);
            --i;
            --j;
        } else if(parent[i][j]==LEFT) {
            --j;
        } else {
            --i;
        }
    }
    
    for(int i=output.size()-1;i>=0;--i) {
        cout<<output[i];
        if(i!=0) cout<<" ";
    }
    cout<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;++i) cin>>arrA[i+1];
    for(int i=0;i<n;++i) cin>>arrB[i+1];
    lcs(m,n);
    return 0;
}