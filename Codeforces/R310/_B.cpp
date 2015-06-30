#include <iostream>
#define MAX_N 1001
using namespace std;

int gears[MAX_N];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>gears[i];
    }

    int k,add = gears[0];
    bool fail = false;
    for(int i=0;i<n;++i){
        if((i&1)==0) { //even
            k = (gears[i]-add+n)%n;
        } else {
            k = (gears[i]+add)%n;
        }

        if(i!=k) {
            fail = true;
        }
    }

    if(fail){
        cout<<"No";
    } else {
        cout<<"Yes";
    }
    return 0;
}
