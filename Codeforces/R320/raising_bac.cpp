#include <cstdio>

using namespace std;

int bits(int n){
    int ans = 0;
    for(int i=0;i<32;++i){
        if(((1<<i)&n)!=0) ++ans;
    }
    return ans;
}

int main(){
    int x;
    scanf("%d",&x);
    printf("%d",bits(x));
    return 0;
}
