#include <iostream>
#define MAX_N 200001
using namespace std;

int main(){
    char line[MAX_N];
    int ans = 0, len;

    cin>>len>>line;
    for(int i=0;i<len;++i){
        if(line[i]=='0') ++ans;
        else --ans;
    }

    if(ans < 0) ans*= -1;
    cout<<ans<<endl;

    return 0;
}
