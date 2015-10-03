#include <cstdio>
#include <algorithm>
#define MAX_N 1001

using namespace std;
typedef long long ll;

int main(){
    char t1[MAX_N], t2[MAX_N];
    int t,len,w[MAX_N],max_false,ans,reel;

    scanf("%d",&t);
    while(t--){
        scanf("%d %s %s",&len,t1,t2);

        scanf("%d",&w[0]);
        for(int i=1;i<=len;++i){
            scanf("%d",&w[i]);
            reel = w[i];
            w[i] = max(w[i], w[i-1]);   
        }

        ans = 0;
   
        for(int i=0;i<len;++i){
            if(t1[i]==t2[i]){
                ++ans;
            }
        }

        if(ans==len){
            printf("%d\n",reel);
        }else{
            printf("%d\n",w[ans]);
        }
    }
    return 0;
}
