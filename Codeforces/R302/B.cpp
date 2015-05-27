#include <iostream>
#include <cmath>

using namespace std;

bool could_be_land(int i,int j){
    if(((i&1)==0 && (j&1)==0) || ((i&1)!=0 && (j&1)!=0))
        return true;
    return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    if(k> ceil((n*n)/2.0)) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(k>0 && could_be_land(i,j)){
                    cout<<"L";
                    --k;
                }
                else    
                    cout<<"S";
            }
            cout<<endl;
        }
    }
    return 0;
}
