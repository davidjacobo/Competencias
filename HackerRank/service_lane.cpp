#include <iostream>
#include <cstring>
#define MAX_N 100001
using namespace std;
int counters[MAX_N][3];

void dp(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)
            counters[i][j]+= counters[i-1][j];
    }
}

int main(){
    int N,T;
    int t, x,y;

    cin>>N>>T;
    memset(counters, 0, sizeof(counters));
    counters[0][0] = counters[0][1] = counters[0][2] = 0;
    for(int i=0;i<N;i++){
        cin>>t;
        if(t==1){
            counters[i+1][0] = 1;
        } else if(t==2) {
            counters[i+1][0] = counters[i+1][1] = 1;
        } else {
            counters[i+1][0] = counters[i+1][1] = counters[i+1][2] = 1;
        }
    }

    dp(N);

    for(int i=0;i<T;i++){
        cin>>x>>y;
        ++x; ++y;
    
        if(counters[y][2]-counters[x-1][2]==y-x+1){
            cout<<3<<endl;
        } else if(counters[y][1]-counters[x-1][1]==y-x+1){
            cout<<2<<endl;
        } else {
            cout<<1<<endl;
        }
    }   
    return 0;
}
