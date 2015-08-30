#include <cstdio>
#define MAX_N 100001

using namespace std;
int nums[MAX_N];

int remove_extra(int n){
    while(n>0 && n%2==0) n>>=1;
    while(n>0 && n%3==0) n/=3;

    return n;
}

int main(){
    int N, t;
    scanf("%d",&N);
    scanf("%d",&t);
    int X = remove_extra(t);
    bool fail = false;
    for(int i=1;i<N;++i){
        scanf("%d",&t);
        t = remove_extra(t);
        if(t != X) fail=true;
    }
    if(fail) printf("No\n");
    else printf("Yes\n");
    return 0;
}
