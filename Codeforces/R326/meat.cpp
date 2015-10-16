#include <iostream>
#define INF (1<<30)
using namespace std;

int main(){
    int n, ans = 0,a,p;
    int mini = INF;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a>>p;
        mini = min(mini, p);
        ans+= (a*mini);
    }
    cout<<ans<<endl;
    return 0;
}
