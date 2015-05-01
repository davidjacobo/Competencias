#include <iostream>
#include <cmath>
using namespace std;

int main(){
    char lineA[1001], lineB[1001];
    int len,i, ans,a,b;
    cin>>len>>lineA>>lineB;

    ans = 0;
    for(i=0;i<len;i++){
        a = lineA[i]-'0';
        b = lineB[i]-'0';
        a = max(a,b)-min(a,b);
        b = 10 - a;
        
        ans+= min(b,a); 
    }
    cout<<ans<<endl;
    return 0;
}
