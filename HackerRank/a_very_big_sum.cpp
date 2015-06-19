#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll sum = 0;
    int n, t;
    cin>>n;
    while(n--){
        cin>>t;
        sum+= t;
    }

    cout<<sum<<endl;
    return 0;
}
