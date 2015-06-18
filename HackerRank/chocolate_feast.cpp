#include <iostream>

using namespace std;

int main(){
    int T,N,C,M,ans,wrappers;
    cin>>T;
    while(T--){
        cin>>N>>C>>M;
        ans = N/C;
        wrappers = ans;

        while(wrappers >= M){
            ++ans;
            wrappers-= (M-1);
        }

        cout<<ans<<endl;
    }
    return 0;
}
