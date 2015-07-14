#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T, A,B;
    cin>>T;
    while(T--){
        cin>>A>>B;
        A = ceil(sqrt(A));
        B = floor(sqrt(B));
        if(A > B){
            cout<<0<<endl;
        } else {
            cout<<(B-A+1)<<endl;
        }
    }
    return 0;
}
