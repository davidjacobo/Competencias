#include <cstdio>
#include <cstring>
#define MAX_N 10000002
using namespace std;
int counter[MAX_N], nums[MAX_N];

int main(){
    int n,t;
    scanf("%d",&n);
    memset(counter, 0, sizeof counter);
    for(int i=0;i<n;++i){
        scanf("%d",&t);
        ++counter[t];
    }

    int ones = 0, ans = 0, div;
    for(int i=0;i<MAX_N;++i){
        if(counter[i]>=2){
            div = counter[i]>>1;
            counter[i]-= (div<<1);

            counter[i+1]+= div;
        }   

        ans+= counter[i];
    }
    printf("%d",ans);
    return 0;
}
