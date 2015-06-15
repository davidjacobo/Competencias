#include <iostream>

using namespace std;

int main(){
    int N,j;
    cin>>N;

    for(int i=N;i>0;--i){
        for(j=1;j<i;++j)
            cout<<" ";
        for(;j<=N;++j)
           cout<<"#";
       cout<<endl; 
    }
    return 0;
}
