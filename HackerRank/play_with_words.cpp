#include <iostream>
#include <cstring>
#include <cmath>
#define MAX_N 3001
using namespace std;

int mat[MAX_N][MAX_N];

void init() {
    memset(mat, 0, sizeof mat);
    for(int i=0;i<MAX_N;++i) mat[i][i] = 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    string input;
    cin>>input;
    n = input.size();
    init();
    for(int i=n-2;i>=0;--i) {
        for(int j=i+1;j<n;++j) {
            mat[i][j] = max(mat[i+1][j-1] + ((input[i]==input[j])?2:0) , max(mat[i+1][j],mat[i][j-1]));
        }
    }
    
    int ans = 0;
    for(int i=0;i<n-1;++i) {
        ans = max(ans, mat[0][i]*mat[i+1][n-1]);
    }
    
    cout<<ans<<endl;
    return 0;
}
