#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int N, bullshit[1001],i,t;
    memset(bullshit, 0, 1001*sizeof(int));
    cin>>N;
    i=0;
    while(i++<N){
        cin>>t;
        bullshit[t]++;
    }

    
    for(i=1;i<=1000;i++)
        if(bullshit[i]){
            cout<<N<<endl;
            N-= bullshit[i];
        }
    return 0;
}
