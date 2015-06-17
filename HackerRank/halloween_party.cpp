#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    int T;
   ll K;
    cin>>T;
    while(T--){
        cin>>K;
        if((K&1)==0){
            cout<<((K>>1)*(K>>1))<<endl;
        } else {
            cout<<((K>>1)*((K>>1)+1))<<endl;
        }
    }
    return 0;
}
