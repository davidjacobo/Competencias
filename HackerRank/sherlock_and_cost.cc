#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 100001
using namespace std;

int A[MAX_N];

void capture(int n) {
    int i = 0;
    while(n--)  cin>>A[i++];
}

int solve(int n) {
    int dp[2][2];
    memset(dp, 0, sizeof dp);
    for(int i=1;i<n;++i) {
        int col = i&1;
        dp[col][0] = max(dp[1-col][0] + 0, dp[1-col][1] + abs(A[i-1] - 1) );
        dp[col][1] = max(dp[1-col][0] + abs(A[i] - 1), dp[1-col][1] + abs(A[i]-A[i-1]));
    }
    return max( max(dp[0][0], dp[0][1]) , max(dp[1][0], dp[1][1]) );
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N;
    cin>>T;
    while(T--) {
        cin>>N;
        capture(N);
        cout<<solve(N)<<endl;
    }
    return 0;
}
