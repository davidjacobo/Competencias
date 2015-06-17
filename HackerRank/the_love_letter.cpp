#include <iostream>
#include <cstring>
#define MAX_LEN 10001
using namespace std;

int main(){
    char line[MAX_LEN];
    int T, len, ans;

    cin>>T;
    while(T--){
        cin>>line;
        len = strlen(line);

        int m = len>>1;
        ans = 0;
        for(int i=0;i<m;++i){
            ans+= abs(line[i]-line[len-i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
