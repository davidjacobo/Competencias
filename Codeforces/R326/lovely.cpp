#include <iostream>
#include <cmath>
#include <vector>
#define MAX_N 1000001

using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll decompose(ll n){
    ll ans = 1;
    if(n%2==0) ans = 2;
    while(n%2==0){
        n/= 2;
    }

    int root = sqrt(n)+1;
    int div = 3;
    while(div<=root){
        if(n%div==0){
            ans*= div;
            while(n%div==0){
                n/= div;
            }

            root = sqrt(n)+1;
        }

        div+= 2;
    }

    if(n!=1){
        ans*= n;
    }

    return ans;
}

int main(){
    ll n;
    cin>>n;
    cout<<decompose(n)<<endl;
       
    return 0;
}
