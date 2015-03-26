#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long long int a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    printf("%lld\n", (long long int)(ceil((double)a/c)*ceil((double)b/c)));
    return 0;
}
