#include <iostream>
#define MAX_N 13
using namespace std;

int A[MAX_N];

int main(){
    int n;
    bool first = true;
    while(1){
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;++i){
            cin>>A[i];
        }

        if(!first) cout<<endl;
        first = false;

        for(int a=0;a<n;++a){
            for(int b=a+1;b<n;++b){
                for(int c=b+1;c<n;++c){
                    for(int d=c+1;d<n;++d){
                        for(int e=d+1;e<n;++e){
                            for(int f=e+1;f<n;++f){   
                                cout<<A[a]<<" "<<A[b]<<" "<<A[c]<<" "<<A[d]<<" "<<A[e]<<" "<<A[f]<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
