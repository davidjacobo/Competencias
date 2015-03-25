#include <iostream>
#define MAX_N 100001
using namespace std;

long long int arr[MAX_N];

void swap(int *a,int *b){
    *a^= *b;
    *b^= *a;
    *a^= *b;
}

int main(){
    int T,N,Q;
    int x,y;
    cin>>T;
    while(T--){
        cin>>N>>Q;
        arr[0] = 0;
        for(int i=1;i<=N;i++){
            cin>>arr[i];
            arr[i]+= arr[i-1];
        }
        
        while(Q--){
            cin>>x>>y;
            x++; y++;
            if(x>y) swap(&x,&y);
            cout<<arr[y]-arr[x-1]<<endl;
        }
        if(T) cout<<endl;
    }
    return 0;
}
