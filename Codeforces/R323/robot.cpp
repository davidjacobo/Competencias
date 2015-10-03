#include <iostream>
#include <cstring>
using namespace std;
int nums[1001];
bool seen[1001];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    memset(seen, false, sizeof seen);

    int ans = -1, last = 0;
    bool taken;
    while(1){
        taken = false;
        for(int i=0;i<n;++i){
            if(!seen[i] && nums[i]<=last){
                seen[i] = true;
                taken = true;
                ++last;
            }
        }

        if(!taken) break;
        else ++ans;

        taken = false;
        for(int i=n-1;i>=0;--i){
            if(!seen[i] && nums[i]<=last){
                seen[i] = true;
                taken = true;
                ++last;
            }
        }
        if(!taken) break;
        else ++ans;
    }

    cout<<ans<<endl;
    return 0;
}
