#include <iostream>
#define MAX_N 101

using namespace std;

char mat[MAX_N][MAX_N], output[MAX_N][MAX_N];

int main(){
    char line[MAX_N];
    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>line;
        for(int j=0;j<n;++j){
            mat[i][j] = line[j];
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                output[i][j] = mat[i][j];
                continue;
            } else {
                if(mat[i-1][j] < mat[i][j] && mat[i+1][j] < mat[i][j] && mat[i][j-1] < mat[i][j] && mat[i][j+1] < mat[i][j]) {
                    output[i][j] = 'X';
                } else {
                    output[i][j] = mat[i][j];
                }
            }
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<output[i][j];
        }
        cout<<endl;
    }
    return 0;
}
