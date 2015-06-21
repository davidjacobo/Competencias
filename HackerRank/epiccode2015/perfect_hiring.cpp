#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    int N,P,X,t,j;
    ll max_rank, rank;
    cin>>N>>P>>X;
    for(int i=0;i<N;++i){
        cin>>t;
        rank = (ll)P*t;
        if(rank > max_rank) {
            max_rank = rank;
            j = i;
        }
        P-= X;
    }

    cout<<(j+1)<<endl;
    return 0;
}
