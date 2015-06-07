#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_LEN 1000
#define MAX_N 2000002

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll triang;

void build(){
    triang.clear();

    triang.push_back(0);
    for(int i=1;i<MAX_N;++i)
        triang.push_back(i + triang[i-1]);
}

int main(){
    char line[MAX_LEN];
    build();
    vll::iterator it_low, it_up;

    ll a,b;
    while(1){
        sscanf(gets(line), "%lld %lld", &a,&b);
        if(0==a && 0==b) break;
        it_low = lower_bound(triang.begin(), triang.end(), a);
        it_up = upper_bound(triang.begin(), triang.end(), b);
        printf("%d\n", (it_up - it_low));
    }
    return 0;
}
