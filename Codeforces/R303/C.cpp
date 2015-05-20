#include <iostream>
#define MAX_N 100001

using namespace std;
int X[MAX_N], H[MAX_N];

int main(){
    int n, x, h, ans = 0;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x>>h;
        X[i] = x;
        H[i] = h;
    }

    ans = min(2, n); 
    for(int i=1;i<n-1;++i){
            //try to push backwards first
            if(X[i]-H[i]>X[i-1]){
                ++ans;
            } else if(X[i]+H[i]<X[i+1]) {
                ++ans;
                X[i]+= H[i];
            }
    }
    cout<<ans<<endl;
    return 0;
}
