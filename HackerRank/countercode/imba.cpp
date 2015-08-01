#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;

int main(){
    int T,N;
    bool first;
    scanf("%d",&T);
    stack<int> s;

    while(T--){
        scanf("%d",&N);
        first = true;
        if((N&1)!=0){
            //Odd number
            printf("%d",(int)ceil(N/2.0));
            first = false;
        }

        for(int p=1,q=N,counter=0;counter<N/2;++counter,++p,--q){
            s.push(q), s.push(p);
        }

        while(!s.empty()){
            if(!first) printf(" ");
            first = false;
            
            printf("%d",s.top());
            s.pop();
        }
        printf("\n");
    }
}
