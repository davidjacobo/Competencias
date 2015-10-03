#include <iostream>
#include <cstring>

using namespace std;
bool X[51], Y[51];

int main(){
    int n, x,y;
    cin>>n;
    memset(X, false, sizeof X);
    memset(Y, false, sizeof Y);
    for(int i=0;i<n*n;++i){
        cin>>x>>y;
        if(!X[x] && !Y[y]){
            cout<<(i+1)<<" ";
            X[x] = true;
            Y[y] = true;
        }
    }
    return 0;
}
