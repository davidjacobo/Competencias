#include <iostream>

using namespace std;

int main(){
    int n, x1,y1,x2,y2;
    int ans = 0;
    cin>>n;
    while(n--){
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<=x2;++i){
            for(int j=y1;j<=y2;++j){
                ++ans;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
