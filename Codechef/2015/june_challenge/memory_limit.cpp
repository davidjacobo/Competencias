#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int T,N,a,last;
    ll max_val;
    cin>>T;
    while(T--){
        cin>>N>>a;
        last = max_val = a;
        --N;

        while(N--){
            cin>>a;
            if(last < a) max_val+= a-last;
            last = a;
        }

        cout<<max_val<<endl;
    }
    return 0;
}
