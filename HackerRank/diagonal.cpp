#include <iostream>
#include <cmath>
#define MAX_N 101
using namespace std;

int mat[MAX_N][MAX_N];

int main(){
    int N, diag1, diag2;
    cin>>N;

    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            cin>>mat[i][j];

    diag1 = diag2 = 0;
    for(int i=0;i<N;++i){
        diag1+= mat[i][i];
        diag2+= mat[i][N-i-1];
    }

    diag1 = abs(diag1 - diag2);
    cout<<diag1<<endl;
    return 0;
}
