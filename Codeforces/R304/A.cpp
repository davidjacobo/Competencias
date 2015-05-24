#include <iostream>

using namespace std;

int main(){
    long long k,w,n;

    cin>>k>>w>>n;
    k = ((n*(n+1))>>1)*k;
    if(w >= k) cout<<0<<endl;
    else cout<<(k-w)<<endl; 
}
