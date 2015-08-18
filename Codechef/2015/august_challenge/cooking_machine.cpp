#include <cstdio>
#include <cmath>

using namespace std;

int calc_power(int a){
    return (int)(log((double)a)/log(2.0));
}

bool is_power(int a){
    int temp = calc_power(a);
    return a == pow(2, temp);
}

int main(){
    int T,a,b,ans;
    bool done;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&a,&b);
        ans = 0;

        while(a>b){
            ++ans;
            a>>=1;
        }

        done = false;
        while(a>1){
            if(a==b){
                done = true;
                break;
            } else if(is_power(a)){
                ans+= calc_power(b/a);
                done = true;
                break;
            }
            ++ans;
            a>>=1;
        }

        if(!done){
            //Then I reached one, what is 2^x == b? we need x
            ans+= calc_power(b);
        }

        printf("%d\n", ans);
    }
    return 0;
}
