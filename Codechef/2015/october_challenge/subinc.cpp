#include <cstdio>

using namespace std;
typedef unsigned long long ll;

int main(){
    int t,n,a,last;
    ll counter, ans;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);

        counter = 1;
        ans = 0;
        scanf("%d",&last);
        for(int i=1;i<n;++i){
            scanf("%d",&a);

            if(a<last){
                ans+= ((counter*(counter+1))>>1);
                counter = 0;
            }
            last = a;
            ++counter;
        }

        ans+= ((counter*(counter+1))>>1);

        printf("%lld\n",ans);
    }
    return 0;
}
