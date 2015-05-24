#include <iostream>
#include <cstring>
#define MAX_D 101
using namespace std;

bool used_day[MAX_D];

int main(){
    int T,n,temp;
    cin>>T;
    while(T--){
        cin>>n;
        memset(used_day, false, sizeof(used_day));
        for(int i=0;i<n;++i){
            cin>>temp;
            used_day[temp] = true;
        }

        int ans = 0;
        for(int i=0;i<MAX_D;++i)
            if(used_day[i]) ++ans;

        cout<<ans<<endl;
    }
    return 0;
}
