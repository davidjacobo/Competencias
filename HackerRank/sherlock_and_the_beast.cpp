#include <iostream>
#define SUCCESS 1
#define FLAIL -1  //pun intended
using namespace std;

int solve(int n){
    int div = n/3;
    int i, y;

    for(int x=div;x>=0;--x){
        y = n - (3*x);
        if(y%5==0){
            for(i=0;i<(x*3);++i)
                cout<<5;
            for(;i<n;++i)
                cout<<3;
            cout<<endl;
            return SUCCESS;
        }
    }
    return FLAIL;
}

int main(){
    int T, N;
    cin>>T;
    while(T--){
        cin>>N;
        if(N<3) {
            cout<<-1<<endl;
        } else {
            N = solve(N);
            if(N==FLAIL) {
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}
