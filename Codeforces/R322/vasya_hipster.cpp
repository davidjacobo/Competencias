#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int m = min(a,b);
    int ma = max(a,b);
    cout<<m<<" "<<((ma-m)>>1);
    return 0;
}
