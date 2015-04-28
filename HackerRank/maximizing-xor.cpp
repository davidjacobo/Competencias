#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a,b, max_value = 0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        for(int j=i;j<=b;j++){
            max_value = max(max_value, i^j);
        }
    }
    cout<<max_value<<endl;
    return 0;
}
