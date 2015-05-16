#include <iostream>
 
using namespace std;
typedef long long ll;
 
ll gcd(ll A,ll B){
    if(B==0) return A;
    return gcd(B, A%B);
}
 
int main(){
    ll A,B,divisor,temp;
    int T;
    cin>>T;
    while(T--){
        cin>>A>>B;
        if(B==1){ 
            cout<<"Yes"<<endl;
            continue;
        }
 
        bool fail = false;
        do{
            divisor = gcd(max(A,B), min(A,B));
            B/= divisor;
 
            if(divisor==1 && B!=1) {
                fail=true;
                break;
            }
        }while(divisor > 1);
 
        if(!fail){
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
