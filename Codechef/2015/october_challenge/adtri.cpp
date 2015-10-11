#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX_N 5000001
using namespace std;
bool is_hyp[MAX_N], is_triple[MAX_N];

bool is_even(int n){
    return ((n&1)==0);
}

void build(){
    //For a sqrt(5000000) boundary, generating O(N^2) pairs 
    //and building all the Pigatorean triples is not an overkill
    //Also remember that the multiples of the original triples
    //can build a valid triple.
    memset(is_hyp, false, sizeof is_hyp);
    memset(is_triple, false, sizeof is_triple);
    int root = sqrt(MAX_N)+1;
    int a,b,c,even;
    for(int n=1;n<root;++n){
        int n2 = n*n;
        for(int m=1;m<n;++m){
            int m2 = m*m;
            even = 0;

            a = n2-m2;
            b = (m*n)<<1;
            c = n2+m2;
            if(c >= MAX_N) break;
            if(is_even(a)) ++even;
            if(is_even(b)) ++even;
            if(is_even(c)) ++even;

            if(even==3 || even==1){
                is_triple[c] = true;
            }
        }
    }

    for(int i=1;i<MAX_N;++i){
        if(is_triple[i]){
            for(int j=i;j<MAX_N;j+=i){
                is_hyp[j] = true;
            }
        }
    }
}

int main(){
    int n,t;
    build();
    
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(is_hyp[n]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
