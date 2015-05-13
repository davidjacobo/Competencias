#include <iostream>
#include <cmath>
#define INF (1<<30)
using namespace std;

int main(){
    int T, N, A, sum, min;
    cin>>T;
    while(T--){
        cin>>N;
        min = INF;
        sum = 0;
        while(N--){
            cin>>A;
            sum+= A;
            if(A < min) min = A; 
        }

        if(min==1){
            cout<<-1<<endl;
        } else {
            cout<<(sum-min+2)<<endl;
        }
    }
    return 0;
}
