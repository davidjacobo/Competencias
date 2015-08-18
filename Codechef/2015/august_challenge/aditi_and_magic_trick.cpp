#include <cstdio>
#include <vector>
#define LIMITE 1000000000000000000LL

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

vi fib_series;

void build(){
    ll n = 2, last =1, t;
    fib_series.push_back(0);
    fib_series.push_back(1);
    fib_series.push_back(2);
    while(n < LIMITE){
        t = n;
        n+= last;
        last = t;
        fib_series.push_back(n);
    }
}

int main(){
    vi::iterator it;
    int T,ans;
    ll n;
    build();

    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        it = lower_bound(fib_series.begin(),fib_series.end(),n);
        ans = it-fib_series.begin();
        if(*it!=n) --ans;

        printf("%d\n",ans);
    }
}
