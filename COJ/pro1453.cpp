#include <cstdio>

using namespace std;

int bits_on(int mask,int n){
    int ans = 0;
    for(int i=0;i<n;++i)
        if(mask&(1<<i)) ++ans;
    return ans;
}

int xor_fun(int mask,int n){
    int ans = 0;
    for(int i=0;i<n;++i){
        if(mask&(1<<i))
            ans^= i;
    }
    return bits_on(ans, n);
}

int main(){
    int n,k,ans;
    while(scanf("%d %d",&n,&k)!=EOF){
        ans = 0;
        for(int bits=0;bits<(1<<(1<<n));++bits){
            int t = xor_fun(bits, 1<<n);
            if(t==k) ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
