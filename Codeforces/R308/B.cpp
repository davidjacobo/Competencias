#include <iostream>

using namespace std;
typedef long long ll;

ll sum(int n){
    ll ans = 0;
    int base = 1000000000;
    ll digits = 10;

    while(n){
        if(n >= base){
            ans+= (n-base+1)*digits;
            n = base-1;
        }

        --digits;
        base/= 10;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<sum(n)<<endl;
    return 0;
}
