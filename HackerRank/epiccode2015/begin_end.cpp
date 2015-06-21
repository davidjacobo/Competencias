#include <cstdio>
#include <cstring>
#define MAX_N 1000001
using namespace std;
typedef long long ll;
ll counter[26];

int main(){
    memset(counter, 0, sizeof counter);
    int len;
    char line[MAX_N];
    scanf("%d %s",&len,line);

    for(int i=0;i<len;++i){
        ++counter[line[i]-'a'];
    }

    ll ans = 0;
    for(int i=0;i<26;++i){
        ans+= counter[i];
        if(counter[i]>0)
            ans+= ((counter[i]*(counter[i]-1))>>1);
    }
    printf("%lld\n", ans);

    return 0;
}
