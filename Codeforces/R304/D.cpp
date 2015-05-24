#include <cstdio>
#include <cstring>
#define MAX_N 5000001
#define INV -1
using namespace std;

int divisors[MAX_N];

void build(){
    int prime_div[MAX_N];
    bool is_prime[MAX_N];
    memset(divisors, INV, sizeof(divisors));
    memset(is_prime, true, sizeof(is_prime));
    
    divisors[0] = divisors[1] = 0;
    divisors[2] = 1;
    for(int i=4;i<MAX_N;i+=2){
        is_prime[i] = false;
        prime_div[i] = 2;
    }
    
    for(int i=3;i<MAX_N;i++){
        if(!is_prime[i]){
            divisors[i] = divisors[i/prime_div[i]]+ 1;
        } else {
            divisors[i] = 1;
            for(int j=i<<1;j<MAX_N;j+=i){
                is_prime[j] = false;
                prime_div[j] = i;
            }
        }
    }
    
    for(int i=1;i<MAX_N;++i)
        divisors[i]+= divisors[i-1];
}

int main(){
    int a,b,T;
    build();
    
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&a,&b);
        if(a==b) {
            printf("0\n");
        } else {
            printf("%d\n",(divisors[a]-divisors[b]));
        }
    }
    return 0;
}
