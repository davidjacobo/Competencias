#include <iostream>
#include <cstring>
#define MAX_N 102

using namespace std;
int num[MAX_N];

int main(){
    memset(num, 0, sizeof num);
    int n,init,end;
    cin>>n;

    init = MAX_N;
    end = -1;
    for(int i=0;i<n;++i){
        cin>>num[i];
        if(num[i] ==1){
            init = min(init, i);
            end = max(end,i);
        }
    }

    if(end==-1){
        cout<<0<<endl;
    }else{
        int ans = end-init+1;
        int j;
        for(int i=init+1;i<=end;++i){
            if(num[i]==0 && num[i-1]==0){
                --ans;
                for(j=i;j<end && num[j]==0;++j){
                    --ans;
                }
                i = j-1;
            }   
        }
        cout<<ans<<endl;
    }
    return 0;
}
