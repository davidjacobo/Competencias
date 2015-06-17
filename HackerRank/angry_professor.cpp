#include <iostream>

using namespace std;

int main(){
    int T,n,k,t, ans;
    cin>>T;
    while(T--){
        cin>>n>>k;
        ans = 0;
        for(int i=0;i<n;++i){
            cin>>t;
            if(t<=0) ++ans;
        }

        if(ans >= k) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
